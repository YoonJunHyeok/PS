def solution(s):
    stack = []
    
    for c in s:
        if len(stack) != 0 and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
        
    return 1 if len(stack) == 0 else 0