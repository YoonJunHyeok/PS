from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def OOM(n, x, y):
    if x < 0 or x >= n or y < 0 or y >= n:
        return True
    return False

def solution(board):
    N = len(board)
    answer = 0
    
    visited = [[[False]*4 for _ in range(N)] for _ in range(N)] # [x][y][dir] 별 방문 여부
    q = deque()
    q.append((0, 0, 1, 0)) # x, y, dir, time
    visited[0][0][1] = visited[0][1][3] = True
    
    while q:
        x1, y1, cur_dir, cur_time = q.popleft()
        x2 = x1 + dx[cur_dir]
        y2 = y1 + dy[cur_dir]
        
        if (x1, y1) == (N - 1, N - 1) or (x2, y2) == (N - 1, N - 1):
            answer = cur_time
            break
        
        # 상하좌우
        for dir in range(4):
            nx1, ny1 = x1 + dx[dir], y1 + dy[dir]
            nx2, ny2 = x2 + dx[dir], y2 + dy[dir]
            
            if OOM(N, nx1, ny1) or OOM(N, nx2, ny2):
                continue
            if board[nx1][ny1] == 1 or board[nx2][ny2] == 1:
                continue
            if visited[nx1][ny1][cur_dir] or visited[nx2][ny2][(cur_dir + 2) % 4]:
                continue
            
            q.append((nx1, ny1, cur_dir, cur_time + 1))
            visited[nx1][ny1][cur_dir] = visited[nx2][ny2][(cur_dir + 2) % 4] = True
        
        # 로봇의 현재 날개 기준 회전
        for idx in [1, 3]:
            dir = (cur_dir + idx) % 4
            nx1, ny1 = x1, y1
            nx2, ny2 = x1 + dx[dir], y1 + dy[dir]
            rx, ry = x2 + dx[dir], y2 + dy[dir]
            
            if OOM(N, nx2, ny2) or OOM(N, rx, ry):
                continue
            if board[nx2][ny2] == 1 or board[rx][ry] == 1:
                continue
            if visited[nx1][ny1][dir] or visited[nx2][ny2][(dir + 2) % 4]:
                continue
                
            q.append((nx1, ny1, dir, cur_time + 1))
            visited[nx1][ny1][dir] = visited[nx2][ny2][(dir + 2) % 4] = True
        
        # 로봇의 반대 날개 기준 회전
        for idx in [1, 3]:
            dir = (cur_dir + idx) % 4
            nx1, ny1 = x2 + dx[dir], y2 + dy[dir]
            nx2, ny2 = x2, y2
            rx, ry = x1 + dx[dir], y1 + dy[dir]
            
            if OOM(N, nx1, ny1) or OOM(N, rx, ry):
                continue
            if board[nx1][ny1] == 1 or board[rx][ry] == 1:
                continue
            if visited[nx1][ny1][(dir + 2) % 4] or visited[nx2][ny2][dir]:
                continue
                
            q.append((nx1, ny1, (dir + 2) % 4, cur_time + 1))
            visited[nx1][ny1][(dir + 2) % 4] = visited[nx2][ny2][dir] = True
            
    return answer