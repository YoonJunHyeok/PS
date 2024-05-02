def solution(nums):
    s = set()
    for n in nums:
        s.add(n)
    answer = len(nums) / 2 if len(s) >= len(nums) / 2 else len(s)
    return answer