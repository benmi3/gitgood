use std::process::exit;

fn main() {
    println!("Hello, world!");
    let mut int_array = vec![0, 1];

    do_fibonacci(&mut int_array, 145)
}

fn do_fibonacci(int_array: &mut Vec<i64>, max_value: i64) {
    if int_array.len() <= 1 {
        println!("There needs to be 2 or more items in this list");
        exit(0)
    };
    int_array.sort();
    println!("this is the new array :{:?}", &int_array);

    let mut counter = 0;

    loop {
        counter += 1;
        let x = int_array[counter - 1];
        let y = int_array[counter];
        let new_num = x + y;
        println!("new number is :{:?}", &new_num);
        int_array.push(new_num);

        if int_array[int_array.len() - 1] >= max_value {
            break;
        }
    }
}
