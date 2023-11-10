fn main() {
    println!("Remove Duplicates from Sorted Array");
    let mut nums = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    let result = remove_duplicates(&mut nums);
    println!(" the new vec: {:?}", nums);
    println!("result: {:?}", result)
}

fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    nums.dedup_by(|a, b| a.eq(&b));
    nums.len() as i32
}
