import sys
input = sys.stdin.readline

N = int(input().strip())
nums = []
for _ in range(N):
    nums.append(int(input().strip()))

sorted_nums = sorted(nums)
used = [False] * N

"""
2 6 3 8 7
2 3 6 7 8
"""

answer = 0

for (i, num) in enumerate(nums):
    idx = 0
    for (j, sorted_num) in enumerate(sorted_nums):
        if sorted_num == num:
            idx = j
            break

    if idx == 0:
        if not used[idx + 1]:
            answer += 1
    elif idx == N - 1:
        if not used[idx - 1]:
            answer += 1
    else:
        if not used[idx - 1] and not used[idx + 1]:
            answer += 1

    used[idx] = True

print(answer)