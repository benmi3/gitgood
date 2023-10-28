fn main() {
    println!("88. Merge Sorted Array");
    let mut nums1: Vec<i32> = vec![1, 2, 3, 0, 0, 0];
    let m = 3;
    let mut nums2: Vec<i32> = vec![2, 5, 6];
    let n = 3;
    println!("This is the lists before merging ");
    println!("nums1: {:?}", &nums1);
    println!("nums2: {:?}", &nums2);
    merge_list(&mut nums1, m, &mut nums2, n);
    println!("This is the lists after merging");
    println!("nums1: {:?}", nums1);
    println!("nums2: {:?}", nums2)
}

fn merge_list(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    for p in 0..n {
        nums1[m as usize + p as usize] = nums2[p as usize]
    }
    nums1.sort()
}
