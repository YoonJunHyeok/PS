from collections import Counter

def solution(N, stages):    
    fail_rates = [(i, 0) for i in range(1, N + 1)]
    cnts = Counter(stages)
    
    cur_clear = len(stages)
    for i in range(1, N + 1):
        if cur_clear == 0:
            break
        
        if i not in cnts:
            continue
            
        fail_rate = cnts[i] / cur_clear
        cur_clear -= cnts[i]
        
        fail_rates[i - 1] = (i, fail_rate)   
        
    fail_rates.sort(key=lambda x: (-x[1], x[0]))
    answer = [idx for (idx, _) in fail_rates]
    
    return answer