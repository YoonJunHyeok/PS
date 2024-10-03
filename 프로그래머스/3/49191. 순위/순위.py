def solution(n, results):
    graph = [[0 for _ in range(n)] for _ in range(n)]
    
    for A, B in results:
        graph[A - 1][B - 1] = 1
        graph[B - 1][A - 1] = -1
        
    for i in range(n):
        for x in range(n):
            for y in range(n):
                if graph[x][y] == 0:
                    if graph[x][i] == 1 and graph[i][y] == 1:
                        graph[x][y] = 1
                    if graph[x][i] == -1 and graph[i][y] == -1:
                        graph[x][y] = -1
                        
    answer = sum([
            1 if sum([1 if result != 0 else 0 for result in row]) == n - 1
            else 0
            for row
            in graph
        ])
    return answer