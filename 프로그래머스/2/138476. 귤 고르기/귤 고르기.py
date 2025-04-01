from collections import defaultdict

def do_count(tangerines: list) -> dict:
    ret = defaultdict(int)
    
    for tangerine in tangerines:
        ret[tangerine] += 1
        
    return ret

def solution(k, tangerine):
    answer = 0
    
    size_count = do_count(tangerine)
    
    size_count_sorted = sorted(size_count.items(), key=lambda x: -x[1])
    
    cur_cnt = 0
    for size, count in size_count_sorted:
        cur_cnt += count
        answer += 1
        
        if cur_cnt >= k:
            break
    
    return answer