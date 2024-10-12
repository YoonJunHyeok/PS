def solution(money):
    answer = 0
    
    N = len(money)
    
    if N == 1 or N == 2:
        return max(money)
    
    dp = [[0] * N for _ in range(2)]
    
    dp[0][0] = money[0]
    for idx in range(1, N - 1):
        dp[0][idx] = max(dp[0][idx - 1], dp[0][idx - 2] + money[idx])
    for idx in range(1, N):
        dp[1][idx] = max(dp[1][idx - 1], dp[1][idx - 2] + money[idx])
        
    return max(dp[0][N - 2], dp[1][N - 1])