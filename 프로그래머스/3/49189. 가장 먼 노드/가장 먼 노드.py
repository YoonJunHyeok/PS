from collections import deque

def solution(n, edge):
    answer = 0
    
    dist = [-1] * (n+1)
    dist[1] = 0
    
    adjs = [[] for _ in range(n+1)]
    
    for l, r in edge:
        adjs[l].append(r)
        adjs[r].append(l)
    
    q = deque()
    q.append(1)

    while q:
        cur = q.popleft()
        
        for nxt in adjs[cur]:
            if dist[nxt] != -1:
                continue
            
            dist[nxt] = dist[cur] + 1
            q.append(nxt)
            
    max_dist = max(dist)
    for n in dist:
        if n == max_dist:
            answer += 1
    
    return answer