import time

def brute_force(nums, target):

    for i in nums:
        for j in nums:
            if (i + j == target):
                print(target, i, j)
                return

    print("not found")
    return

if __name__ == "__main__":
    nums = []
    targets = []

    start = time.time()
    with open("./listNumbers-1000000.txt") as numbers:
        for num in numbers:
            nums.append(int(num))

    with open("./listNumbers-1000000-nsol.txt") as numbers:
        for num in numbers:
            targets.append(int(num))

    for target in targets:
        brute_force(nums, target)


    end = time.time()
    print("average = " + str((end - start) / len(targets)))