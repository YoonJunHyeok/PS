from itertools import product
from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def is_out(x, y):
    if x < 0 or x >= 5 or y < 0 or y >= 5:
        return True
    return False

def is_valid(board, x, y):
    q = deque()
    q.append((x, y, 0))
    visited = [[False] * 5 for _ in range(5)]
    visited[x][y] = True
    
    while q:
        curX, curY, curD = q.popleft()
        
        if curD >= 2:
            continue
        
        for dir in range(4):
            nxtX = curX + dx[dir]
            nxtY = curY + dy[dir]
            
            if is_out(nxtX, nxtY) or visited[nxtX][nxtY] or board[nxtX][nxtY] == 'X':
                continue
                
            if board[nxtX][nxtY] == 'P':
                break
            
            q.append((nxtX, nxtY, curD + 1))
        else:
            visited[curX][curY] = True
            continue
        break
    else:
        return True
    
    return False
        

def solution(places):
    answer = []
    
    for place in places:
        board = [[e for e in row] for row in place]
        for x, y in product(range(5), repeat=2):
            if board[x][y] == 'P' and not is_valid(board, x, y):
                break
        else:
            answer.append(1)
            continue
        answer.append(0)
                        
    return answer