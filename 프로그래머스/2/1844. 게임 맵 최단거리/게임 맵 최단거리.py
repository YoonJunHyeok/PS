from collections import deque

def solution(maps):    
    n = len(maps)
    m = len(maps[0])
    
    moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    q = deque([(0, 0)])
    
    while len(q) != 0:
        (cur_x, cur_y) = q.popleft()
        
        for move in moves:
            nxt_x = cur_x + move[0]
            nxt_y = cur_y + move[1]
            
            if nxt_x < 0 or nxt_x >= n or nxt_y < 0 or nxt_y >= m:
                continue
            if maps[nxt_x][nxt_y] != 1:
                continue
            
            maps[nxt_x][nxt_y] = maps[cur_x][cur_y] + 1
            q.append((nxt_x, nxt_y))
    
    return maps[n - 1][m - 1] if maps[n - 1][m - 1] != 1 else -1