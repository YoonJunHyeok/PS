import sys
input = sys.stdin.readline

def solve(lst):
    if len(lst) == 1:
        return lst

    length = len(lst)
    zero_list = [0] * (length//3)
    return solve(lst[:length//3]) + zero_list + solve(lst[length//3*2::])

while True:
    tmp = input()
    if not tmp:
        break

    N = int(tmp)

    lst = [1] * (3 ** N)
    ans_list = solve(lst)
    for n in ans_list:
        print("-", end="") if n else print(" ", end="")

    print()