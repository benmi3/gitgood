def fibonacci(prev_num, next_num):
    new_num = prev_num + next_num
    return new_num


def Main():
    list_of_numbers = [0, 1]
    loop_counter = 0
    while list_of_numbers[-1] < 144:
        list_of_numbers.append(
            fibonacci(
                prev_num=list_of_numbers[loop_counter],
                next_num=list_of_numbers[1 + loop_counter],
            )
        )
        loop_counter = loop_counter + 1
        print(list_of_numbers)


if __name__ == "__main__":
    Main()
