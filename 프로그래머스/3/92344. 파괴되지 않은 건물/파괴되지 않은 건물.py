def solution(board, skill):
    # 카카오 해설 봄 -> 2차원 배열 누적합
    N = len(board)
    M = len(board[0])
    
    accum = [[0] * (M+1) for _ in range(N+1)]
    
    for cur_skill in skill:
        skill_type, r1, c1, r2, c2, degree = cur_skill
        
        if skill_type == 1:
            degree = -degree
        
        accum[r1][c1] += degree
        accum[r1][c2 + 1] -= degree
        accum[r2 + 1][c1] -= degree
        accum[r2 + 1][c2 + 1] += degree
    
    # 행별 누적합 계산
    for i in range(N):
        for j in range(1, M):
            accum[i][j] += accum[i][j - 1]
    
    # 열별 누적합 계산
    for j in range(M):
        for i in range(1, N):
            accum[i][j] += accum[i - 1][j]
    
    answer = 0
    for i in range(N):
        for j in range(M):
            board[i][j] += accum[i][j]
            answer = answer + 1 if board[i][j] > 0 else answer
        
    return answer