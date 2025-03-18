def solution(cap, n, deliveries, pickups):
    answer = 0
    
    cur_d, cur_p = 0, 0
    for idx in range(n - 1, -1, -1):
        cur_d -= deliveries[idx]
        cur_p -= pickups[idx]
        
        max_visit = 0
        while cur_d < 0 or cur_p < 0:
            cur_d += cap
            cur_p += cap
            max_visit += 1
            
        answer += (idx + 1) * max_visit * 2
    
    return answer