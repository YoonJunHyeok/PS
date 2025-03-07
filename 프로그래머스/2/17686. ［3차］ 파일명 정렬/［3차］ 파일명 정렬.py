import re
from functools import cmp_to_key

def compare(lhs, rhs):
    if lhs[0].lower() != rhs[0].lower():
        return -1 if lhs[0].lower() < rhs[0].lower() else 1
    
    if int(lhs[1]) != int(rhs[1]):
        return int(lhs[1]) - int(rhs[1])
    
    return 0

def solution(files):
    hnt_files = list()
    
    pattern = r"^([\D]+)(\d{1,5})(.*)$"
    
    for file in files:
        head, number, tail = re.match(pattern, file).groups()
        hnt_files.append((head, number, tail))
    
    hnt_files.sort(key=cmp_to_key(compare))
    answer = [head+number+tail for (head, number, tail) in hnt_files]
    return answer