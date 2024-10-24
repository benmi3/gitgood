use clap::{Arg, Command};

fn main() {
    println!("Hello, world!");
    let matches = Command::new("CliTesting One")
        .version("0.1")
        .author("Benjamin")
        .about("Just some practice with clap")
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
        .get_matches();

    let input: &String = matches.get_one("input").expect("Input is required");

    let output: &String = matches.get_one("output").expect("Output is required");

    println!("Given input {}", input);
    println!("Given output {}", output)
}
