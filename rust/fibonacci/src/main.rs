fn main() {
    println!("Hello, world!");
    let mut int_array = vec![0];

    do_fibonacci(&mut int_array)
}

fn do_fibonacci(int_array: &mut Vec<i8>) {
    if int_array.len() > 1 {
        int_array.push(0)
    };
    println!("this is the new array :{:?}", int_array)
}
