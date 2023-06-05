def freq_arr(n, m, arr):
    freq = [0] * (m + 1)
    for i in range(n):
        freq[arr[i]] += 1

    for i in range(m):
        print(freq[i + 1])


n, m = map(int, input().split())
arr = list(map(int, input().split()))


freq_arr(n, m, arr)


""" 
10 5
1 2 3 4 5 3 2 1 5 3
"""
