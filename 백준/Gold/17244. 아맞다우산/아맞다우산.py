import sys
from collections import deque
input = sys.stdin.readline

dxs = [1, 0, -1, 0]
dys = [0, 1, 0, -1]

N, M = map(int, input().split())

board = []
# 0번부터 {item_cnt - 1}번까지
dict = {}
item_cnt = 0
start = end = None
for i in range(M):
    row = list(input().strip())
    board.append(row)

    for j, c in enumerate(row):
        if c == 'S':
            start = (i, j)
        elif c == 'E':
            end = (i, j)
        elif c == 'X':
            dict[(i, j)] = item_cnt
            item_cnt += 1

# 현재 위치, 챙긴 아이템(00000 -> 11111), 걸린 시간
q = deque([(start, 0, 0)])
full_item = (1 << item_cnt) - 1

visited = [[[False] * (full_item + 1) for _ in range(N)] for _ in range(M)]

while len(q):
    (curX, curY), cur_state, cur_time = q.popleft()

    if (curX, curY) == end and cur_state & full_item == full_item:
        print(cur_time)
        break

    for dx, dy in zip(dxs, dys):
        nxtX, nxtY = curX + dx, curY + dy

        if nxtX < 0 or nxtX >= M or nxtY < 0 or nxtY >= N:
            continue
        if board[nxtX][nxtY] == '#' or visited[nxtX][nxtY][cur_state]:
            continue

        nxt_state = cur_state
        if board[nxtX][nxtY] == 'X':
            item_idx = dict[(nxtX, nxtY)]
            # 아직 안 주웠음
            if not cur_state & (1 << item_idx):
                nxt_state = cur_state | (1 << item_idx)

        q.append(((nxtX, nxtY), nxt_state, cur_time + 1))
        visited[nxtX][nxtY][nxt_state] = True