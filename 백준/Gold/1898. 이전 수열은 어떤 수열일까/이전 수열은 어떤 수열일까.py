import sys
input = sys.stdin.readline

N = int(input())

# 8 5 7 3 6 4 2 1
# 7 4 8 2 6 5 3 1
# 7 4 8 2 5 5 3 1
is_used = [0] * (N + 1)
for _ in range(N):
    n = int(input())

    if is_used[n] == 1:
        print(n + 1)
    elif n > 1 and not is_used[n - 1]:
        is_used[n - 1] = 1
        is_used[n] = 2
        print(n - 1)
    else:
        is_used[n] = 1
        print(n)