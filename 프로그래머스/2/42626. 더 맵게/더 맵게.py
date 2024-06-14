import heapq

def solution(scoville, K):
    answer = 0
    
    heapq_list = scoville
    heapq.heapify(heapq_list)
    
    while len(heapq_list) >= 2:
        s1 = heapq.heappop(heapq_list)
        
        if s1 >= K:
            break
        
        s2 = heapq.heappop(heapq_list)
        new_s = s1 + (s2 * 2)
        
        heapq.heappush(heapq_list, new_s)
        answer += 1
        
    if heapq_list[0] < K:
        answer = -1 
        
    return answer