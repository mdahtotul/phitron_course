# while loop
num = 1
while num <= 10:
    num += 1
    if num % 2 == 1:
        continue
    print(num)


# for loop
nums = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50]
sum = 0
for num in nums:
    # print(num)
    sum += num


print(sum)


# range function
# range(x, y, increment/decrement)
for num in range(1, 10):
    idx = range(1, 10).index(num)
    print(f"Index -> {idx}, and value -> {num}")
