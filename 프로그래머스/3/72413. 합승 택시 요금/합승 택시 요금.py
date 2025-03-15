from itertools import product

def solution(n, s, a, b, fares):    
    costs = [[-1] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0
    for c, d, f in fares:
        costs[c - 1][d - 1] = costs[d - 1][c - 1] = f
    
    for mid, start, end in product(range(n), repeat=3):
        if costs[start][mid] == -1 or costs[mid][end] == -1:
            continue
            
        if costs[start][end] == -1:
            costs[start][end] = costs[start][mid] + costs[mid][end]
        else:
            costs[start][end] = min(costs[start][end], costs[start][mid] + costs[mid][end])
            
    answer = costs[s - 1][a - 1] + costs[s - 1][b - 1]
    for mid in range(n):
        if costs[s - 1][mid] == -1 or costs[mid][a - 1] == -1 or costs[mid][b - 1] == -1:
            continue
        answer = min(answer, costs[s - 1][mid] + costs[mid][a - 1] + costs[mid][b - 1])
    
    return answer