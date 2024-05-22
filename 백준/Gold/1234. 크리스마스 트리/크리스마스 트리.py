import sys
from math import comb, factorial
input = sys.stdin.readline

N, R, G, B = map(int, input().strip().split())

dp = [[[[0] * (B + 1) for _ in range(G + 1)] for _ in range(R + 1)] for _ in range(N + 1)]

def comb3(n, m):
    return factorial(n) / factorial(m) / factorial(m) / factorial(m)
def solve(n, r, g, b):
    if r < 0 or g < 0 or b < 0:
        return 0
    if n <= 0:
        return 1

    if dp[n][r][g][b] > 0:
        return dp[n][r][g][b]

    dp[n][r][g][b] += solve(n - 1, r - n, g, b)
    dp[n][r][g][b] += solve(n - 1, r, g - n, b)
    dp[n][r][g][b] += solve(n - 1, r, g, b - n)

    if n % 2 == 0:
        m = n // 2
        dp[n][r][g][b] += solve(n - 1, r - m, g - m, b) * int(comb(n, m))
        dp[n][r][g][b] += solve(n - 1, r - m, g, b - m) * int(comb(n, m))
        dp[n][r][g][b] += solve(n - 1, r, g - m, b - m) * int(comb(n, m))
    if n % 3 == 0:
        m = n // 3
        dp[n][r][g][b] += solve(n - 1, r - m, g - m, b - m) * int(comb3(n, m))

    return dp[n][r][g][b]

print(solve(N, R, G, B))