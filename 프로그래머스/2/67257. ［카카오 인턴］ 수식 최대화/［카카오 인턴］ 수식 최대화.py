import re
from math import inf
from itertools import permutations

def calculate(nums: list, ops: list, priority: list) -> int:
    for p_op in priority:        
        while p_op in ops:
            idx = ops.index(p_op)
            if p_op == '*':
                n = nums[idx] * nums[idx + 1]
            elif p_op == '+':
                n = nums[idx] + nums[idx + 1]
            elif p_op == '-':
                n = nums[idx] - nums[idx + 1]
                
            nums[idx] = n
            del nums[idx + 1]
            del ops[idx]
    return abs(nums[0])

def solution(expression):
    num_pattern = '\d+'
    op_pattern = '[\*\+\-]'
    
    nums = list(map(int, re.findall(num_pattern, expression)))
    ops = re.findall(op_pattern, expression)
    
    answer = -inf
    tmp_priority = list(['+', '-', '*'])
    for priority in permutations(tmp_priority):
        result = calculate(nums.copy(), ops.copy(), priority)
        answer = max(answer, result)
    
    return answer