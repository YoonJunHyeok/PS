def solution(land):
    dp = [[0 for _ in range(4)] for _ in range(len(land))]
    dp[0] = land[0].copy()
    
    for i in range(1, len(land)):
        for j in range(0, 4):
            dp[i][j] = max(dp[i - 1][:j] + dp[i - 1][j + 1:]) + land[i][j]
            
    return max(dp[len(land) - 1])
        