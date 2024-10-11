import sys
input = sys.stdin.readline

# 서 -> 남 -> 동 -> 북
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

tornadox = [
    [-1, 1, -2, 2, -1, 1, -1, 1, 0, 0],
    [-1, -1, 0, 0, 0, 0, 1, 1, 2, 1],
    [-1, 1, -2, 2, -1, 1, -1, 1, 0, 0],
    [1, 1, 0, 0, 0, 0, -1, -1, -2, -1]
]
tornadoy = [
    [1, 1, 0, 0, 0, 0, -1, -1, -2, -1],
    [-1, 1, -2, 2, -1, 1, -1, 1, 0, 0],
    [-1, -1, 0, 0, 0, 0, 1, 1, 2, 1],
    [-1, 1, -2, 2, -1, 1, -1, 1, 0, 0]
]
tornado = [0.01, 0.01, 0.02, 0.02, 0.07, 0.07, 0.1, 0.1, 0.05]

def OOM(n, x, y):
    if x < 0 or x >= n or y < 0 or y >= n:
        return True
    return False

def solve(n, board):
    curx = n // 2
    cury = n // 2
    dir = 0
    dir_dist = 1  # dir 방향으로 이만큼 이동해야 함. 이동 후 dir 전환
    dir_cnt = 0 # 2 되면 dir_dist 1 증가시키고, 0으로 초기화

    ans = 0 # 밖으로 나간 양
    flag = False
    while True:
        for _ in range(dir_dist):
            curx = curx + dx[dir]
            cury = cury + dy[dir]

            if OOM(n, curx, cury):
                flag = True
                break

            total_sand = board[curx][cury]
            board[curx][cury] = 0
            moved_sand = 0

            for idx in range(9):
                nx = curx + tornadox[dir][idx]
                ny = cury + tornadoy[dir][idx]

                cur_sand = int(total_sand * tornado[idx])

                if OOM(n, nx, ny):
                    ans += cur_sand
                else:
                    board[nx][ny] += cur_sand

                moved_sand += cur_sand

            ax = curx + tornadox[dir][-1]
            ay = cury + tornadoy[dir][-1]
            a_sand = total_sand - moved_sand

            if OOM(n, ax, ay):
                ans += a_sand
            else:
                board[ax][ay] += a_sand

        if flag:
            break

        dir = (dir + 1) % 4
        dir_cnt += 1
        if dir_cnt == 2:
            dir_dist += 1
            dir_cnt = 0

    return ans

def main():
    n = int(input())
    board = []
    for _ in range(n):
        row = list(map(int, input().strip().split()))
        board.append(row)

    print(solve(n, board))

if __name__ == '__main__':
    main()