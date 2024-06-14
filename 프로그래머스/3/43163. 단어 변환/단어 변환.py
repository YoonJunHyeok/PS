from collections import deque

def convertible(lhs, rhs):
    cnt = 0
    for l, r in zip(lhs, rhs):
        if l != r:
            cnt += 1
    
    return True if cnt <= 1 else False

def solution(begin, target, words):
    if target not in words:
        return 0
    
    answer = 0
    
    is_used = set([begin])
    dq = deque([(begin, 0)])
    
    while dq:
        cur_word, cur_cnt = dq.pop()
        
        if cur_word == target:
            answer = cur_cnt
            break
        
        for word in words:
            if word in is_used:
                continue
            if not convertible(cur_word, word):
                continue
            
            dq.append((word, cur_cnt + 1))
            is_used.add(word)
    
    return answer