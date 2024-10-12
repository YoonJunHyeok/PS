import sys
from bisect import bisect_left
input = sys.stdin.readline

def solve(N, nums):
    res = [nums[0]]

    for num in nums[1:]:
        if res[-1] < num:
            res.append(num)
        else:
            idx = bisect_left(res, num)
            res[idx] = num

    return len(res)

def main():
    N = int(input())
    nums = list(map(int, input().strip().split()))

    print(solve(N, nums))
if __name__=="__main__":
    main()