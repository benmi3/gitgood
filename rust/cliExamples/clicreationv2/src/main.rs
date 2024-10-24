use clap::{Arg, Command};

fn main() {
    println!("Hello, world!");
    let matches = Command::new("CliTesting One")
        .version("0.2")
        .author("Benjamin")
        .about("Just some practice with clap")
        .subcommand(
            Command::new("resize")
                .about("REEEEsizes an image")
                .arg(
                    Arg::new("input")
                        .short('i')
                        .long("input")
                        .help("Sets the input path")
                        .required(true),
                )
                .arg(
                    Arg::new("output")
                        .short('o')
                        .long("output")
                        .value_name("FILE")
                        .help("Sets the output path")
                        .required(true),
                )
                .arg(
                    Arg::new("width")
                        .short('x')
                        .long("width")
                        .value_name("WIDTH")
                        .help(" Sets the new width")
                        .required(true),
                )
                .arg(
                    Arg::new("height")
                        .short('y') // h is reserved for help
                        .long("height")
                        .value_name("HEIGHT")
                        .help("Sets the new height")
                        .required(true),
                ),
        )
        .subcommand(
            Command::new("convert")
                .about("Converts an image")
                .arg(
                    Arg::new("input")
                        .short('i')
                        .long("input")
                        .value_name("FILE")
                        .help("Sets the input file path")
                        .required(true),
                )
                .arg(
                    Arg::new("output")
                        .short('o')
                        .long("output")
                        .value_name("FILE")
                        .help("Sets the output file path")
                        .required(true),
                )
                .arg(
                    Arg::new("format")
                        .short('f')
                        .long("format")
                        .value_name("FORMAT")
                        .help("Sets the output format example: png, jpg")
                        .required(true),
                ),
        )
        .get_matches();

    match matches.subcommand() {
        Some(("resize", sub_matches)) => {
            //Do resize things
            let input = sub_matches
                .get_one::<String>("input")
                .expect("Input file is required!");
            let output = sub_matches
                .get_one::<String>("output")
                .expect("Output file is required!");
            let width = sub_matches
                .get_one::<String>("width")
                .expect("Width is required!");
            let height = sub_matches
                .get_one::<String>("height")
                .expect("Height is required!");
            println!(
                "Resizing {} to {}x{} and saving to {}",
                input, width, height, output
            );
        }
        Some(("convert", sub_matches)) => {
            // Do converting things
            let input = sub_matches
                .get_one::<String>("input")
                .expect("Input file is required!");
            let output = sub_matches
                .get_one::<String>("output")
                .expect("Output file is required!");
            let format = sub_matches
                .get_one::<String>("format")
                .expect("Width is required!");
            println!(
                "Formatting {} to {} and saving to {}",
                input, format, output
            );
            // your resize logic would go here
        }
        _ => {
            // Do the rest of the things
            println!("No subcommand was matched");
        }
    }
    println!("All complete")
}
