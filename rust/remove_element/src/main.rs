fn main() {
    println!("27. Remove element");
    let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
    let val: i32 = 2;
    let return_value = remove_element(&mut nums, val);
    println!("this is the return value {:?}", return_value);
    println!("this is the rest of numbers {:?}", nums)
}

pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    nums.retain(|&x| x != val);
    nums.len() as i32
}
