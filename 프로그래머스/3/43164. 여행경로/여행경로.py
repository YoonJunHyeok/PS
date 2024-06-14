dict = {}
is_used = []
answer = []
flag = False
N = int()

def DFS(airport, cities):
    global answer, flag
    if flag:
        return
    
    if len(cities) == N + 1:
        answer = cities
        flag = True
        return
    
    if airport not in dict:
        return
    
    for nxt, idx in dict[airport]:
        if is_used[idx]: 
            continue
            
        is_used[idx] = True
        DFS(nxt, cities + [nxt])
        is_used[idx] = False
    
def solution(tickets):
    global dict, is_used, answer, N
    N = len(tickets)
    is_used = [False] * N
    
    for idx, (start, end) in enumerate(tickets):
        if start in dict:
            dict[start].append([end, idx])
        else:
            dict[start] = [[end, idx]]
    
    for start in dict:
        dict[start].sort(key=lambda x: x[0])

    DFS("ICN", ["ICN"])
    
    return answer