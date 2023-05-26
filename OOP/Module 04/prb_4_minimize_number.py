def mini_operations(n, nums):
    count = 0
    while True:
        for i in range(n):
            if nums[i] % 2 == 0:
                nums[i] = nums[i] // 2
            else:
                return count

        count += 1


n = int(input())
nums = list(map(int, input().split()))
print(mini_operations(n, nums))
# print(mini_operations([16, 32, 96]))  # 7
# print(mini_operations([8, 12, 40]))  # 7
# print(mini_operations([5, 6, 8, 10]))  # 0
