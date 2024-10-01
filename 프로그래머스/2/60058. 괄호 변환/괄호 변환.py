def checkCorrect(p):
    stack = []
    for char in p:
        if char == "(":
            stack.append(1)
        elif char == ")":
            if len(stack) == 0:
                return False
            else:
                stack.pop()
                
    return True if len(stack) == 0 else False

def split(p):
    init = p[0]
    stack = [1]
    split_idx = len(p)
        
    for idx, char in enumerate(p[1:]):
        if char == init:
            stack.append(1)
        else:
            stack.pop()
        
        if len(stack) == 0:
            split_idx = idx + 1
            break
            
    return p[:split_idx + 1], p[split_idx + 1:]

def solve(p):
    if p == "":
        return p
    
    u, v = split(p)
    
    if checkCorrect(u):
        return u + solve(v)
    else:
        ret = "("
        ret += solve(v)
        ret += ")"
        for char in u[1:-1]:
            if char == "(":
                ret += ")"
            else:
                ret += "("
        return ret

def solution(p):
    return solve(p)