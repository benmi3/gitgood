fn main() {
    println!("Majority Element!");
    let input = vec![2,2,1,1,1,2,2];
    println!("Input: '{:?}' ", input);
    let output = majority_element(input);
    println!("Output: '{:?}' ", output);
}

fn majority_element(nums: Vec<i32>) -> i32 {
    let mut majority_element = 0;
    let mut majority_element_count = 0;

    for item in nums.iter() {
        let cur_count = nums.iter().filter(|&x| x == item).count();
        println!("{:?}", cur_count);
        if cur_count > majority_element_count {
            majority_element = item.clone();
            majority_element_count = cur_count;
        }
    }
    majority_element as i32
}
