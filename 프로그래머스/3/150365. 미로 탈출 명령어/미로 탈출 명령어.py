from collections import deque

s = ["d", "l", "r", "u"]
dx = [1, 0, 0, -1]
dy = [0, -1, 1, 0]

def is_out(x, y, n, m):
    if x < 1 or x > n or y < 1 or y > m:
        return True
    return False

def solution(n, m, x, y, r, c, k):
    short_cut = abs(x - r) + abs(y - c)
    if short_cut > k or (short_cut % 2 != k % 2):
        return "impossible"
    
    answer = ""
    stack = deque()
    stack.append((x, y, 0, ""))
    
    while stack:
        curX, curY, curDist, curStr = stack.pop()
        
        if (curX, curY, curDist) == (r, c, k):
            answer = curStr
            break
            
        curLeftDist = abs(curX - r) + abs(curY - c)
        if curLeftDist > k - curDist:
            continue
            
        for dir in range(4):
            # 스택이니깐 역 사전 순으로
            nxtX = curX + dx[3 - dir]
            nxtY = curY + dy[3 - dir]
            
            if is_out(nxtX, nxtY, n, m):
                continue
            
            stack.append((nxtX, nxtY, curDist + 1, curStr + s[3 - dir]))
    
    return answer