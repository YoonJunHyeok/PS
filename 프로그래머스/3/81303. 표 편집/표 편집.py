from collections import deque

def solution(n, k, cmd):
    answer = ['O'] * n
    
    adjs = [[idx - 1, idx + 1] for idx in range(n)]
    deleted = deque()
    
    for cur_cmd in cmd:
        if cur_cmd[0] == 'U':
            x = int(cur_cmd[2:])
            for _ in range(x):
                k = adjs[k][0]
                
        elif cur_cmd[0] == 'D':
            x = int(cur_cmd[2:])
            for _ in range(x):
                k = adjs[k][1]
                
        elif cur_cmd[0] == 'C':
            answer[k] = 'X'
            deleted.append(k)
            
            up, down = adjs[k]
            
            if up != -1:
                adjs[up][1] = down
                
            if down != n:
                adjs[down][0] = up
                
            if down == n:
                k = up
            else:
                k = down
            
        elif cur_cmd[0] == 'Z':
            re = deleted.pop()
            answer[re] = 'O'
            
            re_up, re_down = adjs[re]
            
            if re_up != -1:
                adjs[re_up][1] = re
            
            if re_down != n:
                adjs[re_down][0] = re
    
    answer = "".join(answer)
    return answer