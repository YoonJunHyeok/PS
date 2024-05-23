import sys
from itertools import permutations
input = sys.stdin.readline

N = int(input())

board = []
items = [[], [], [], []]
item_to_idx = {
    'J': 0,
    'C': 1,
    'B': 2,
    'W': 3
}

idx_to_answer = {
    0: 'Assassin',
    1: 'Healer',
    2: 'Mage',
    3: 'Tanker'
}

def get_dist(coord1: (int, int), coord2: (int, int)) -> int:
    a1, b1 = coord1
    a2, b2 = coord2
    return abs(a1 - a2) + abs(b1 - b2)

for i in range(N):
    row = list(input().strip())
    board.append(row)

    for j, c in enumerate(row):
        if c == 'H':
            home = (i, j)
        elif c == '#':
            dest = (i, j)
        elif c != 'X':
            items[item_to_idx[c]].append((i, j))

# home -> (item1 -> item2 -> item3) -> dest
answer_dist = sys.maxsize
answer = -1

tmp = [0, 1, 2]
orders = list(permutations(tmp))

for i in range(4):
    for order in orders:
        cur_dist = 0
        # home -> order[0]
        cur_dist += get_dist(home, items[i][order[0]])
        # order[0] -> order[1]
        cur_dist += get_dist(items[i][order[0]], items[i][order[1]])
        # order[1] -> order[2]
        cur_dist += get_dist(items[i][order[1]], items[i][order[2]])
        # order[2] -> dest
        cur_dist += get_dist(items[i][order[2]], dest)

        if cur_dist < answer_dist:
            answer_dist = cur_dist
            answer = i

print(idx_to_answer[answer])