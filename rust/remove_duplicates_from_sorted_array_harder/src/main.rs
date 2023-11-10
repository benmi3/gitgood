fn main() {
    println!("Remove Duplicates from Sorted Array");
    let mut nums = vec![0,0,1,1,1,1,2,3,3];
    println!("contain check: {:?}", nums);
    let result = remove_duplicates(&mut nums);

    println!(" the new vec: {:?}", nums);
    println!("result: {:?}", result)
}

fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    // this is not my solution
    let mut last = (0,-1);

    nums.retain(|num| {
        let result = last.0 == last.1 && last.1 == *num;

        last.0 = last.1;
        last.1 = *num;

        !result
    });

    nums.len() as i32
}


