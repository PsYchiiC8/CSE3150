def unique_nonNaN_cnt(nums, col):
    my_list = []

    for value in nums[col]:
        if value != "NaN" and value not in my_list:
            my_list.append(value)

    return len(my_list)


nums = []