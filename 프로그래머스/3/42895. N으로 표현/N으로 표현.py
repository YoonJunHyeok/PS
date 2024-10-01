def solution(N, number):
    dp = [set() for _ in range(9)]
    
    for step in range(1, 9):
        base = 0
        for _ in range(step):
            base = base * 10 + N
            
        dp[step].add(base)
        
        for i in range(1, step):
            for n in dp[i]:
                for m in dp[step - i]:
                    dp[step].add(n + m)
                    dp[step].add(n * m)
                    if n - m > 0:
                        dp[step].add(n - m)
                    if n // m > 0:
                        dp[step].add(n // m)
                        
        if number in dp[step]:
            return step
    
    return -1