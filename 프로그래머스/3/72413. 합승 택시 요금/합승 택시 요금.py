def solution(n, s, a, b, fares):
    graph = [[20000001] * (n + 1) for _ in range(n + 1)]
    for idx in range(n + 1):
        graph[idx][idx] = 0
    for i, j, cost in fares:
        graph[i][j] = cost
        graph[j][i] = cost
        
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

    answer = graph[s][a] + graph[s][b]
    for k in range(1, n + 1):
        answer = min(answer, graph[s][k] + graph[k][a] + graph[k][b])
                
    return answer