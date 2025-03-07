def solution(m, n, puddles):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    puddles = set(list(map(tuple, puddles)))
    
    dp[1][1] = 1
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if (i, j) == (1, 1):
                continue
            
            if (j, i) in puddles:
                continue
                
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1_000_000_007
                    
    return dp[n][m]