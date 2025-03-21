import heapq
from collections import defaultdict

MAX = 10000001

def solution(n, paths, gates, summits):
    answer = [-1, MAX]
        
    is_summit = [False] * (n + 1)
    for summit in summits:
        is_summit[summit] = True

    adjs = defaultdict(list)
    for i, j, w in paths:
        adjs[i].append((j, w))
        adjs[j].append((i, w))
        
    intensity = [MAX] * (n + 1)
        
    pq = list()
    for gate in gates:
        heapq.heappush(pq, (0, gate))
        intensity[gate] = 0
        
    while pq:
        cur_intensity, cur_node = heapq.heappop(pq)
        
        if intensity[cur_node] < cur_intensity:
            continue
            
        for nxt_node, nxt_intensity in adjs[cur_node]:
            nxt_intensity = max(cur_intensity, nxt_intensity)
            
            if intensity[nxt_node] <= nxt_intensity:
                continue
                
            intensity[nxt_node] = nxt_intensity
            
            if is_summit[nxt_node]:
                continue
                
            heapq.heappush(pq, (nxt_intensity, nxt_node))
    
    summits.sort()
    for summit in summits:
        if intensity[summit] < answer[1]:
            answer = [summit, intensity[summit]]
    
    return answer