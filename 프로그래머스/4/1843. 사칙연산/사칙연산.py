def solution(arr):
    nums = list(map(int, arr[::2]))
    ops = arr[1::2]
    N = len(nums)
    
    max_dp = [[float('-inf')] * N for _ in range(N)]
    min_dp = [[float('inf')] * N for _ in range(N)]
    
    for i in range(N):
        max_dp[i][i] = min_dp[i][i] = nums[i]
        
    for step in range(1, N):
        for i in range(N - step):
            j = i + step
            
            for k in range(i, j):
                if ops[k] == '+':
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k + 1][j])
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k + 1][j])
                else:
                    max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k + 1][j])
                    min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k + 1][j])
    return max_dp[0][N - 1]