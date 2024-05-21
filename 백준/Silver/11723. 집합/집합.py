import sys
input = sys.stdin.readline

M = int(input())
s = set()

for _ in range(M):
    tmp = input().strip().split()

    if len(tmp) == 1:
        if tmp[0] == "all":
            s = set(list(range(1, 21)))
        elif tmp[0] == "empty":
            s = set()
    else:
        command, num = tmp
        num = int(num)

        if command == "add":
            s.add(num)
        elif command == "remove":
            s.discard(num)
        elif command == "check":
            print(1 if num in s else 0)
        elif command == "toggle":
            if num in s:
                s.discard(num)
            else:
                s.add(num)
