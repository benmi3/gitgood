fn main() {
    println!("27. Remove element");
    let mut nums = vec![3, 2, 2, 3];
    let val: i32 = 3;
    let return_value = remove_element(&mut nums, val);
    println!("this is the return value {:?}", return_value)
}

pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    nums.retain(|num| *num != val);
    nums.len() as i32
}
