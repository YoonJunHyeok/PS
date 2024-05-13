def solution(priorities, location):
    stack = [(p, idx) for (idx, p) in enumerate(priorities)]
    
    answer = 0
    while 1:
        (curP, curIdx) = stack[0]
        (maxP, maxIdx) = max(stack, key = lambda x: x[0])
        
        if maxP > curP:
            stack.pop(0)
            stack.append((curP, curIdx))
        elif curIdx == location:
            answer += 1
            break
        else:
            answer += 1
            stack.pop(0)
            
    
    return answer