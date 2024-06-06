# x^2 - y^2 = G
# (x+y)(x-y) = G = a * b
# x = (a + b) / 2
import sys
import math
input = sys.stdin.readline

G = int(input())

ans = []
for a in range(1, math.ceil(math.sqrt(G))):
    if G % a == 0:
        b = int(G / a)

        if a == b or (a + b) % 2 == 1:
            continue
        ans.append(int((a + b) / 2))

if not ans:
    print(-1)
else:
    ans.sort()
    for n in ans:
        print(n)