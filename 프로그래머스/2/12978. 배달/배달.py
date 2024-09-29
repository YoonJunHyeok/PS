import heapq

def solution(N, road, K):
    answer = 0
    graph = [[] for _ in range(N + 1)]
    dists = [float('inf') for _ in range(N + 1)]
    dists[1] = 0
    queue = []
    heapq.heappush(queue, (dists[1], 1))

    for [node1, node2, cost] in road:
        graph[node1].append((node2, cost))
        graph[node2].append((node1, cost))
        
    
    while queue:
        cur_dist, cur_node = heapq.heappop(queue)
        
        if cur_dist > dists[cur_node]:
            continue
            
        for nxt_node, nxt_cost in graph[cur_node]:
            if dists[nxt_node] > cur_dist + nxt_cost:
                dists[nxt_node] = cur_dist + nxt_cost
                heapq.heappush(queue, (cur_dist + nxt_cost, nxt_node))
        
    answer = sum([1 if dist <= K else 0 for dist in dists])
    
    return answer