// Roman numerals to int practice
fn main() {
    let roman_numerals = "MMCDXXI";
    println!("Roman numerals: {:?}", &roman_numerals);
    let int_numberals = get_value(roman_numerals);
    println!("Turned into int = {:?}", int_numberals);
}

fn match_value(c: &char) -> i32 {
    match c {
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000,
        _ => 0,
    }
}

fn get_value(str_list: &str) -> i32 {
    let mut values_ = 0;
    let mut prev_num = 0;

    let mut char_list: Vec<char> = str_list.chars().collect::<Vec<_>>();
    char_list.reverse();

    for letter in char_list.clone().into_iter() {
        let new_val = match_value(&letter);

        if prev_num > new_val {
            values_ = values_ - new_val;
        } else {
            values_ = values_ + new_val;
        }

        prev_num = new_val;
    }
    values_
}
