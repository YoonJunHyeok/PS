def solution(info, edges):    
    global answer
    answer = 0
    visited = [False] * len(info)
    
    def dfs(sheep_cnt, wolf_cnt):
        global answer
        if wolf_cnt >= sheep_cnt:
            return
        else:
            answer = max(answer, sheep_cnt)
        
        for p_idx, c_idx in edges:
            if visited[p_idx] and not visited[c_idx]:
                visited[c_idx] = True
                if info[c_idx] == 0:
                    dfs(sheep_cnt + 1, wolf_cnt)
                else:
                    dfs(sheep_cnt, wolf_cnt + 1)
                visited[c_idx] = False
    
    visited[0] = True
    dfs(1, 0)
    
    return answer