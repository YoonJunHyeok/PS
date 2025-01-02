def match(str_a, str_b):
    if (str_a, str_b) in [("[", "]"), ("(", ")"), ("{", "}")]:
        return True
    return False

def check(s):
    stack = list()
    cnt = 0
    for c in s:
        if c in ["[", "(", "{"]:
            stack.append(c)
        else:
            if len(stack) == 0 or not match(stack[-1], c):
                return (False, 0)
            else:
                stack.pop()
            
        if len(stack) == 0:
            cnt += 1
    return (True, cnt)

def solution(s):
    s_len = len(s)
    flag = False
    
    for _ in range(s_len):
        is_valid, cnt = check(s)
        if is_valid:
            answer = cnt
            flag = True
            break
        else:
            s = s[1:] + s[0]
            
    if not flag:
        answer = 0
    
    return answer