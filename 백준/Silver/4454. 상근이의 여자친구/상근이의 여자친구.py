import sys
input = sys.stdin.readline

def calculate_oil(a, b, c, d, v, m):
    return m * ((a * v ** 3) + (b * v ** 2) + (c * v) + d)

while True:
    try:
        a, b, c, d, m, t = map(float, input().split())
        l, r = 0, 1000000
        while l <= r:
            v = (l + r) // 2
            if calculate_oil(a, b, c, d, v / 1000, m) <= t:
                l = v + 1
            else:
                r = v - 1

        ans = str(r / 1000)
        tmp = ans.split('.')
        if len(tmp[1]) < 2:
            tmp[1] = tmp[1] + '0' * (2 - len(tmp[1]))
        elif len(tmp[1]) > 2:
            tmp[1] = tmp[1][0:2]

        ans = '.'.join(tmp)
        print(ans)
    except:
        break
