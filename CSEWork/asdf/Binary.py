import time

def brute_force_sum(nums, target):
    for i in nums:
        for j in nums:
            if (i + j == target):
                return
    return

def binary_search_sum(nums, target):
    nums.sort()
    for num in nums:
        if (binary_search(nums, target - num)):
            return
    return


def binary_search(nums, n):
    low = 0
    high = len(nums) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2

        if nums[mid] < n:
            low = mid + 1
        elif nums[mid] > n:
            high = mid - 1
        else:
            return True

    return False


if __name__ == "__main__":
    nums = []
    with open('listNumbers-100000.txt', 'r') as numbers:    #change txt file name as needed
        for num in numbers:
            nums.append(int(num))
    numbers.close()

    targets = []
    with open('listNumbers-100000-nsol.txt', 'r') as numbers:   #change txt file name as needed
        for num in numbers:
            targets.append(int(num))
    numbers.close()

    start = time.time()
    for target in targets:
        brute_force_sum(nums, target)

    end = time.time()

    avgTime_bruteForce = (end - start) / len(targets)

    start = time.time()
    for target in targets:
        binary_search_sum(nums, target)

    end = time.time()

    avgTime_binarySearch = (end - start) / len(targets)

    print(f"Brute Force {avgTime_bruteForce}")
    print(f"Binary Search {avgTime_binarySearch}")





