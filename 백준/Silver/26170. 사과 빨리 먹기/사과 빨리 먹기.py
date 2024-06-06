import sys
from collections import deque
input = sys.stdin.readline

dxs = [1, 0, -1, 0]
dys = [0, 1, 0, -1]

board = [list(map(int, input().strip().split())) for _ in range(5)]
r, c = map(int, input().strip().split())
ans = 25

def dfs(curx, cury, curdist, curcnt):
    global ans

    if board[curx][cury] == 1:
        curcnt += 1

    if curcnt == 3:
        ans = min(curdist, ans)
        return

    for dx, dy in zip(dxs, dys):
        nx, ny = curx + dx, cury + dy

        if not (0 <= nx < 5 and 0 <= ny < 5):
            continue

        if board[nx][ny] == -1:
            continue

        tmp = board[curx][cury]
        board[curx][cury] = -1
        dfs(nx, ny, curdist + 1, curcnt)
        board[curx][cury] = tmp

dfs(r, c, 0, 0)
if ans == 25:
    ans = -1

print(ans)