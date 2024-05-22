import sys
from math import factorial, sqrt, floor
input = sys.stdin.readline

N = int(input())

dp = [sys.maxsize] * (N + 1)
dp[1] = 1

# n번째에 n!값, 1부터 시작
fact = [factorial(i) for i in range(9)]

# +, *, !
for num in range(2, N + 1):
    # 2 ~ N 까지의 num 만들기
    # Addition
    for j in range(1, num // 2 + 1):
        if dp[num] > dp[j] + dp[num - j]:
            dp[num] = dp[j] + dp[num - j]

    # Multiplication
    for j in range(1, int(sqrt(num)) + 1):
        if num % j == 0 and dp[num] > dp[j] + dp[num // j]:
            dp[num] = dp[j] + dp[num // j]

    # Factorial
    for j, val in enumerate(fact):
        if val > num:
            break
        if val == num and dp[num] > dp[j]:
            dp[num] = dp[j]

print(dp[N])