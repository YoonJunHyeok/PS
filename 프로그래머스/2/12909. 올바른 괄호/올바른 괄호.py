def solution(s):
    stack = []
    for c in s:
        if len(stack) == 0 and c == ')':
            return False
        elif len(stack) == 0 or c == stack[-1]:
            stack.append(c)
        else:
            stack.pop()
    
    answer = True if len(stack) == 0 else False

    return answer