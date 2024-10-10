import sys
from itertools import product
input = sys.stdin.readline

dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

def solve(n, board, command):
    cloud = {(n - 2, 0), (n - 2, 1), (n - 1, 0), (n - 1, 1)}

    for d, s in command:
        # 1
        cloud = set(map(lambda x: ((x[0] + (dx[d] * s) + n) % n, (x[1] + (dy[d] * s) + n) % n), cloud))

        # 2
        for x, y in cloud:
            board[x][y] += 1

        # 4
        for x, y in cloud:
            cnt = 0
            for dir in [1, 3, 5, 7]:
                nx = x + dx[dir]
                ny = y + dy[dir]

                if nx < 0 or nx >= n or ny < 0 or ny >= n:
                    continue

                if board[nx][ny] > 0:
                    cnt += 1

            board[x][y] += cnt

        # 3 & 5
        tmp_cloud = set()
        for x, y in product(range(n), repeat=2):
            if (x, y) in cloud:
                continue

            if board[x][y] >= 2:
                tmp_cloud.add((x, y))
                board[x][y] -= 2

        cloud = tmp_cloud.copy()

    return sum([sum(row) for row in board])

def main():
    n, m = map(int, input().strip().split())
    board = []
    command = []
    for _ in range(n):
        row = list(map(int, input().strip().split()))
        board.append(row)
    for _ in range(m):
        d, s = map(int, input().strip().split())
        d -= 1
        s %= n
        command.append((d, s))

    print(solve(n, board, command))

if __name__=='__main__':
    main()