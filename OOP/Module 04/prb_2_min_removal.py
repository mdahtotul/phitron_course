def good_sequence(n, nums):
    if n == 1:
        return 1

    count = 0
    freq = []
    for i in range(1, n + 5):
        freq.append(0)

    for i in range(n):
        freq[nums[i]] += 1

    for i in range(1, len(freq)):
        if freq[i] > 0:
            if i > freq[i]:
                count += freq[i]
            elif i < freq[i]:
                count += freq[i] - i

    return count


n = int(input())
nums = list(map(int, input().split()))
print(good_sequence(n, nums))
