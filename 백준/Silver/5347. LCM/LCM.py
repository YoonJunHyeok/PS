n = int(input())

def GCD(n, m):
    if n < m:
        n, m = m, n
    return GCD(m, n % m) if n % m != 0 else m

def LCM(n, m):
    return n * m / GCD(n, m)

for _ in range(n):
    a, b = map(int, input().split())

    print(int(LCM(a, b)))

