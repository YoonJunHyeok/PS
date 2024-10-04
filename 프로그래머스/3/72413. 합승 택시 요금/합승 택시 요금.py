from itertools import product

def solution(n, s, a, b, fares):
    graph = [[20000001] * (n + 1) for _ in range(n + 1)]
    for idx in range(n + 1):
        graph[idx][idx] = 0
    for i, j, cost in fares:
        graph[i][j] = graph[j][i] = cost
        
    for k, i, j in product(range(1, n + 1), repeat=3):
        if graph[i][j] > graph[i][k] + graph[k][j]:
            graph[i][j] = graph[i][k] + graph[k][j]
                
    return min(graph[s][k] + graph[k][a] + graph[k][b] for k in range(1, n + 1))