from functools import cmp_to_key

def compare(a, b):
    return -(int(a+b) - int(b+a)) 

def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=cmp_to_key(compare))
    if numbers[0] == "0":
        return "0"
    return ''.join(numbers)