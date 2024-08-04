from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def solution(maps):
    answer = []
    
    N = len(maps)
    M = len(maps[0])
    visited = [[False] * M for _ in range(N)]
    
    for i, row in enumerate(maps):
        for j, v in enumerate(row):
            if v == 'X':
                continue
            
            if visited[i][j]:
                continue
                
            q = deque([(i, j)])
            stay = int(v)
            visited[i][j] = True
            
            while q:
                curX, curY = q.popleft()
                
                for idx in range(4):
                    nxtX = curX + dx[idx]
                    nxtY = curY + dy[idx]
                    
                    if nxtX < 0 or nxtX >= N or nxtY < 0 or nxtY >= M:
                        continue
                        
                    if maps[nxtX][nxtY] == 'X':
                        continue
                        
                    if visited[nxtX][nxtY]:
                        continue
                    
                    q.append((nxtX, nxtY))
                    stay += int(maps[nxtX][nxtY])
                    visited[nxtX][nxtY] = True
                
            answer.append(stay)            
    
    if not answer:
        answer.append(-1)
        
    answer.sort()
    
    return answer
