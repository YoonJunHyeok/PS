def solution(triangle):
    dp = [[0 for _ in range(idx + 1)] for idx in range(len(triangle))]
    dp[0][0] = triangle[0][0]
    
    for step in range(1, len(triangle)):
        for idx in range(step + 1):
            if idx == 0:
                dp[step][idx] = dp[step - 1][idx] + triangle[step][idx]
            elif idx == step:
                dp[step][idx] = dp[step - 1][idx - 1] + triangle[step][idx]
            else:
                dp[step][idx] = max(dp[step - 1][idx - 1], dp[step - 1][idx]) + triangle[step][idx]
    
    return max(dp[-1])