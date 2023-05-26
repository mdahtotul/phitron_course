# https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/S?fbclid=IwAR1qi6o8WBDOrdzcZ--U5YO_40SSQmmLbZ8jggB6CFIRqog1ukVL_Z2wK2s


def max_split(str):
    idx_l = 0
    idx_r = 0
    balanced_str = []

    for ch in str:
        if ch == "L":
            idx_l += 1
        elif ch == "R":
            idx_r += 1

        if idx_l == idx_r:
            balanced_str.append(str[: idx_l + idx_r])
            str = str[idx_l + idx_r :]
            idx_l = 0
            idx_r = 0

    return len(balanced_str), balanced_str


str = input().strip()
count, words = max_split(str)
print(count)
for word in words:
    print(word)

""" 
Input
LLRR LLLRRR LLLRR
"""
