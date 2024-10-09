def solve(N, arr, S):
    for idx in range(N):
        if S == 0:
            break

        max_num = max(arr[idx:idx + S + 1])
        max_idx = arr.index(max_num)

        S -= (max_idx - idx)
        for tmp_idx in range(max_idx, idx, -1):
            arr[tmp_idx], arr[tmp_idx - 1] = arr[tmp_idx - 1], arr[tmp_idx]
    return arr

def main():
    N = int(input())
    arr = list(map(int, input().strip().split()))
    S = int(input())

    ans = solve(N, arr, S)

    for num in ans:
        print(num, end=" ")

if __name__=='__main__':
    main()