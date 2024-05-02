def solution(nums):
    s = set(nums)
    answer = min(len(nums)/2, len(s))
    return answer