use clap::{Arg, Command};
use std::path::Path;

fn main() {
    println!("Hello, world!");
    let matches = Command::new("CliTesting One")
        .version("0.3")
        .author("Benjamin")
        .about("Just some practice with clap")
        .subcommand(
            Command::new("resize").about("Resizes an image").arg(
                Arg::new("input")
                    .short('i')
                    .long("input")
                    .value_name("FILE")
                    .help("Sets the input file paths.")
                    .required(true)
                    .num_args(1..) // allows one or more values
                    .value_parser(clap::builder::ValueParser::new(|file_path: &str| {
                        if Path::new(file_path).exists() {
                            Ok(file_path.to_string())
                        } else {
                            Err(String::from("Input file does not exist"))
                        }
                    })),
            ),
        )
        .get_matches();
    if let Some(sub_matches) = matches.subcommand_matches("resize") {
        let input_files: Vec<String> = sub_matches
            .get_many("input")
            .expect("Input files are required")
            .cloned()
            .collect();
        // process each input file
        for input_file in input_files {
            println!("Resizing {}", input_file);
            // main resizing process goes here
        }
    }
    println!("All complete")
}
