def majority_element(nums):
    print(f" {nums} ")
    check_item = 0
    for item in nums:
        if nums.count(item) > nums.count(check_item):
            check_item = item
    return check_item


if __name__ == "__main__":
    input = [2, 2, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4]
    output = majority_element(input)
    print(f"The output is: {output}")
