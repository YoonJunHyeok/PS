from collections import deque

def solution(people, limit):
    answer = 0
    
    dq = deque(sorted(people))
    while len(dq) >= 2:
        if dq[0] + dq[-1] <= limit:
            dq.popleft()
            dq.pop()
            answer += 1
        else:
            dq.pop()
            answer += 1
    
    answer = answer + 1 if len(dq) > 0 else answer
    
    return answer