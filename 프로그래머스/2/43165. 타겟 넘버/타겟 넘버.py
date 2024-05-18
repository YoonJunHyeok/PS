from itertools import product

def solution(numbers, target):
    all_nums = [(x, -x) for x in numbers]
    possible_values = list(map(sum, product(*all_nums)))
    
    return possible_values.count(target)