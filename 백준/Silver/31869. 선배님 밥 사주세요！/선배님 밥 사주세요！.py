import sys
from functools import cmp_to_key
input = sys.stdin.readline

N = int(input())

schedule = []
finance = {}
check = [False] * 77

for _ in range(N):
    S, W, D, P = input().strip().split()
    schedule.append([S, int(W), int(D), int(P)])

for _ in range(N):
    name, M = input().strip().split()
    finance[name] = int(M)

for S, W, D, P in schedule:
    idx = W * 7 + D
    if finance[S] >= P:
        check[idx] = True

ans = -1
tmp = 0
for b in check:
    if b:
        tmp += 1
    else:
        ans = max(ans, tmp)
        tmp = 0
ans = max(ans, tmp)
print(ans)