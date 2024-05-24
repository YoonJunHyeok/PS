import sys
input = sys.stdin.readline

def init():
    global N, C, W, trees
    N, C, W = map(int, input().split())
    trees = []
    for _ in range(N):
        trees.append(int(input()))
def solve():
    global N, C, W, trees

    max_tree = max(trees)
    max_money = -1
    for length in range(1, max_tree + 1):
        cur_money = 0

        for tree in trees:
            if tree < length:
                continue

            cnt, leftover = divmod(tree, length)

            if leftover == 0:
                cost = C * (cnt - 1)
            else:
                cost = C * cnt

            earn = W * cnt * length - cost

            if earn > 0:
                cur_money += earn

        max_money = max(max_money, cur_money)

    return max_money

if __name__ == '__main__':
    init()
    print(solve())