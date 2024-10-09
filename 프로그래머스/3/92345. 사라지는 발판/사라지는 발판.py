dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
n, m = 0, 0

# 현재 상태에서 각자 최선의 플레이를 할 때, 움직이는 횟수
# solve의 return 값이 홀수라면, cur 플레이어가 승리함을 의미
# cur -> op -> cur로 3번 움직이고, op가 움직일 수 없어 끝남.
# solve의 return 값이 짝수라면, cur 플레이어가 패배함을 의미
# cur -> op로 2번 움직이고, cur가 움직일 수 없어 끝남.
def solve(board, curx, cury, opx, opy, step):
    # 같은 위치에 있었는데, 전 라운드에서 상대가 움직여서 발판이 없어짐.
    # 전 라운드에서 게임이 이미 끝났으므로 0 return
    if board[curx][cury] == 0:
        return 0
    
    # 이길 수 없음이 초기 가정
    # 움직일 수 없다면 0, return
    best_round = 0
    for dir in range(4):
        nx = curx + dx[dir]
        ny = cury + dy[dir]
        
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if board[nx][ny] == 0:
            continue
        
        board[curx][cury] = 0
        cur_round = solve(board, opx, opy, nx, ny, step + 1) + 1
        board[curx][cury] = 1
        
        if best_round % 2 == 0 and cur_round % 2 == 1:
            best_round = cur_round
        elif best_round % 2 == 1 and cur_round % 2 == 1:
            best_round = min(best_round, cur_round)
        elif best_round % 2 == 0 and cur_round % 2 == 0:
            best_round = max(best_round, cur_round)
    
    return best_round

def solution(board, aloc, bloc):
    global n, m
    n = len(board)
    m = len(board[0])
    
    return solve(board, aloc[0], aloc[1], bloc[0], bloc[1], 0)