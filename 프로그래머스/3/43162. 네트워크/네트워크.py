def solution(n, computers):
    answer = 0
    
    adjs = [[] for _ in range(n)]
    is_visited = [False] * n
    
    def DFS(idx):
        for nxt in adjs[idx]:
            if not is_visited[nxt]:
                is_visited[nxt] = True
                DFS(nxt)
    
    for i, rows in enumerate(computers):
        for j, connected in enumerate(rows):
            if connected:
                adjs[i].append(j)
                
    for idx in range(n):
        if is_visited[idx]:
            continue
        
        is_visited[idx] = True
        DFS(idx)
        answer += 1
    
    return answer