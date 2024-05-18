ans = 0

def dfs(numbers, target, idx, cur_sum):
    global ans
    
    if idx == len(numbers):
        if cur_sum == target:
            ans += 1
        return

    dfs(numbers, target, idx + 1, cur_sum + numbers[idx])
    dfs(numbers, target, idx + 1, cur_sum - numbers[idx])
    
def solution(numbers, target):
    dfs(numbers, target, 0, 0)
    
    return ans