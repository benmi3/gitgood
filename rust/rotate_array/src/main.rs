fn main() {
    println!("Rotate array!");
    let mut nums = vec![-1, -100, 3, 99];
    println!("Before rotating: {:?}", nums);
    rotate(&mut nums, 2);
    println!("After rotating: {:?}", nums);

}

fn rotate(nums: &mut Vec<i32>, k: i32) {
    if k as usize <= nums.len() {
        let mut count = 0;
        loop {
            if count >= k {
                break;
            }
            let item = nums.remove(nums.len() - 1);
            nums.insert(0, item);
            count += 1;
        }
    }
}
