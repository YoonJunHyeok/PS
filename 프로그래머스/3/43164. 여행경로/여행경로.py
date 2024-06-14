dict = {}
is_used = []
N = int()

def DFS(airport, cities):    
    if len(cities) == N + 1:
        return cities
    
    if airport not in dict:
        return
    
    for nxt, idx in dict[airport]:
        if is_used[idx]: 
            continue
            
        is_used[idx] = True
        ret = DFS(nxt, cities + [nxt])
        is_used[idx] = False
        
        if ret:
            return ret
    
def solution(tickets):
    global dict, is_used, N
    answer = []
    N = len(tickets)
    is_used = [False] * N
    
    for idx, (start, end) in enumerate(tickets):
        if start in dict:
            dict[start].append([end, idx])
        else:
            dict[start] = [[end, idx]]
    
    for start in dict:
        dict[start].sort(key=lambda x: x[0])

    answer = DFS("ICN", ["ICN"])
    
    return answer