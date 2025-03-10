import sys
from collections import deque

INF = sys.maxsize

dx = [1, 0, -1, 0] # 아래, 오른쪽, 위, 왼쪽
dy = [0, 1, 0, -1]

def is_out(x, y, n):
    if x < 0 or x >= n or y < 0 or y >= n:
        return True
    return False

def is_vertical(l_dir, r_dir):
    if l_dir % 2 != r_dir % 2:
        return True
    return False

def solution(board):
    n = len(board)
    cost = [[[INF] * 4 for _ in range(n)] for _ in range(n)]
    q = deque()
    
    for idx in range(4):
        cost[0][0][idx] = 0
        
    if board[0][1] != 1:
        cost[0][1][1] = 100
        q.append((0, 1, 1))
    if board[1][0] != 1:
        cost[1][0][0] = 100
        q.append((1, 0, 0))
    
    while q:
        curX, curY, prevDir = q.popleft()
        
        for curDir in range(4):
            nxtX = curX + dx[curDir]
            nxtY = curY + dy[curDir]
            
            if is_out(nxtX, nxtY, n) or board[nxtX][nxtY] == 1:
                continue
            
            if is_vertical(prevDir, curDir):
                nxtCost = cost[curX][curY][prevDir] + 600
            else:
                nxtCost = cost[curX][curY][prevDir] + 100

            if nxtCost < cost[nxtX][nxtY][curDir]:
                cost[nxtX][nxtY][curDir] = nxtCost
                q.append((nxtX, nxtY, curDir))
    
    return min(cost[n - 1][n - 1][0], cost[n - 1][n - 1][1])