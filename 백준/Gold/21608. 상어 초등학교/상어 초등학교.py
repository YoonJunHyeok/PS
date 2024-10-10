import sys
from collections import defaultdict
from itertools import product
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def OOM(N, x, y):
    if x < 0 or x >= N or y < 0 or y >= N:
        return True
    return False

def seat(N, like, order):
    board = [[0]*N for _ in range(N)]

    for idx in order:
        x, y = None, None
        like_cnt = 0
        empty_cnt = 0

        for curx, cury in product(range(N), repeat=2):
            if board[curx][cury] != 0:
                continue

            cur_like_cnt = 0
            cur_empty_cnt = 0

            for dir in range(4):
                nx = curx + dx[dir]
                ny = cury + dy[dir]

                if OOM(N, nx, ny):
                    continue

                nxt_idx = board[nx][ny]

                if nxt_idx == 0:
                    cur_empty_cnt += 1
                elif nxt_idx in like[idx]:
                    cur_like_cnt += 1

            if x == None and y == None:
                like_cnt, empty_cnt, x, y = cur_like_cnt, cur_empty_cnt, curx, cury
            elif cur_like_cnt > like_cnt:
                like_cnt, empty_cnt, x, y = cur_like_cnt, cur_empty_cnt, curx, cury
            elif cur_like_cnt == like_cnt and cur_empty_cnt > empty_cnt:
                like_cnt, empty_cnt, x, y = cur_like_cnt, cur_empty_cnt, curx, cury

        board[x][y] = idx
    return board

def get_satisfaction(N, board, like):
    score = [0, 1, 10, 100, 1000]
    satisfaction = 0

    for curx, cury in product(range(N), repeat=2):
        cur_idx = board[curx][cury]
        cnt = 0

        for dir in range(4):
            nx = curx + dx[dir]
            ny = cury + dy[dir]

            if OOM(N, nx, ny):
                continue

            nxt_idx = board[nx][ny]

            if nxt_idx in like[cur_idx]:
                cnt += 1

        satisfaction += score[cnt]

    return satisfaction

def solve(N, like, order):
    board = seat(N, like, order)
    satisfaction = get_satisfaction(N, board, like)
    print(satisfaction)

def main():
    N = int(input())
    like = defaultdict(set)
    order = []

    for _ in range(N*N):
        inputs = list(map(int, input().strip().split()))

        cur_idx = inputs[0]

        order.append(cur_idx)

        for idx in inputs[1:]:
            like[cur_idx].add(idx)

    solve(N, like, order)

if __name__=='__main__':
    main()