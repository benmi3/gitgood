use clap::{Arg, Command};
use image::{DynamicImage, ImageBuffer, Rgba};
use indicatif::{MultiProgress, ProgressBar, ProgressStyle};
use rayon::prelude::*;
use std::path::Path;
use std::{fs, time::Duration};

fn load_image(filepath: &str) -> Result<DynamicImage, image::ImageError> {
    image::open(filepath)
}

fn rotate_image_90_clockwise(
    img: &ImageBuffer<Rgba<u8>, Vec<u8>>,
) -> ImageBuffer<Rgba<u8>, Vec<u8>> {
    let (width, height) = img.dimensions();

    let mut new_img = ImageBuffer::new(height, width); // new image dimensions are swapped

    img.enumerate_pixels().for_each(|(x, y, pixel)| {
        let new_x = height - y - 1; // new x is (height-y-1)
        let new_y = x; // new y is the old x

        new_img.put_pixel(new_x, new_y, *pixel);
    });

    new_img
}

fn main() {
    println!("Lets make a cli");
    let matches = Command::new("CLI Images Processor")
        .version("0.5")
        .author("Benjamin Jørgensen")
        .about("Practice project for creating CLIs for image processing")
        .arg(
            Arg::new("input")
                .short('i')
                .value_name("INPUT_DIRECTORY")
                .help("Sets the input directory to use")
                .required(true),
        )
        .arg(
            Arg::new("output")
                .short('o')
                .value_name("OUTPUT_DIRECTORY")
                .help("Sets the output directory to use")
                .required(true),
        )
        .get_matches();

    let input_dir = matches
        .get_one::<String>("input")
        .expect("failed at getting input dir");

    let output_dir = matches
        .get_one::<String>("output")
        .expect("failed at getting output dir");

    fs::create_dir_all(output_dir).expect("Failed at creating output dir");

    println!("Image Processing - Parallel Processing with Threat Pool - rayon");
    // get all images paths in the parallel directory
    let image_dir = Path::new(input_dir);
    let image_paths = fs::read_dir(image_dir)
        .expect("Failed to read directory")
        //.into_iter()
        .filter_map(Result::ok)
        .filter(|entry| entry.file_type().is_ok() && entry.file_type().unwrap().is_file())
        .map(|entry| entry.path())
        .collect::<Vec<_>>();

    let multi_progress = MultiProgress::new();
    let main_progress = multi_progress.add(ProgressBar::new(image_paths.len() as u64));
    main_progress.set_style(ProgressStyle::default_bar()
            .template("{spinner:.green} [{elapsed_precise}] [{wide_bar:.magenta/blue}] {pos}/{len} files processed ({eta})")
            .unwrap()
            .progress_chars("#>-"));

    let spinner = multi_progress.add(ProgressBar::new_spinner());
    spinner.set_style(
        ProgressStyle::default_spinner()
            .template("{spinner:.blue} Processing images... {wide_msg}")
            .unwrap(),
    );
    spinner.enable_steady_tick(Duration::from_millis(100));

    // process images in parallel using rayon thread pool
    image_paths.par_iter().for_each(|img_path| {
        // Image handling -- Start
        let img = load_image(img_path.to_str().unwrap()).expect("Failed to load image");
        let rotated_img = rotate_image_90_clockwise(&img.to_rgba8());

        let processed_path = format!(
            "{}/processed_{}",
            output_dir,
            img_path.file_name().unwrap().to_str().unwrap()
        );
        rotated_img
            .save(processed_path)
            .expect("Failed to save processed file.");
        // Image handling -- Stop

        // update progress bars
        main_progress.inc(1);
        spinner.set_message(format!(
            "Processing {}",
            img_path.file_name().unwrap().to_str().unwrap()
        ));
    });
    main_progress.finish_with_message("All files processed.");
    spinner.finish_with_message("Processing complete.");
}
