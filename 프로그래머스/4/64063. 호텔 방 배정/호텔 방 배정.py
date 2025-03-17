import sys

sys.setrecursionlimit(1000000)

def find_empty(idx):
    global goto
    
    if idx not in goto:
        goto[idx] = idx + 1
        return idx
    
    ret = find_empty(goto[idx])
    goto[idx] = ret + 1
    return ret

def solution(k, room_number):
    global goto
    
    answer = []
    goto = {}
    
    for rn in room_number:
        answer.append(find_empty(rn))
    
    return answer