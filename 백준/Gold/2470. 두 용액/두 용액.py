import sys
input = sys.stdin.readline

def solve(N, nums):
    nums.sort()

    start = 0
    end = N - 1

    min_value = float('inf')
    ans = [0, 0]
    while start < end:
        cur_value = nums[start] + nums[end]

        if abs(cur_value) < abs(min_value):
            min_value = cur_value
            ans[0] = nums[start]
            ans[1] = nums[end]

            if cur_value == 0:
                break

        if cur_value > 0:
            end -= 1
        else:
            start += 1

    return ans

def main():
    N = int(input())
    nums = list(map(int, input().strip().split()))

    ans = solve(N, nums)
    for n in ans:
        print(n, end=" ")

if __name__=="__main__":
    main()