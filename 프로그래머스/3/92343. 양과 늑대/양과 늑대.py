def solution(info, edges):
    answer = 0
    
    node_cnt = len(info)
    state_cnt = 1 << node_cnt
    visited = [False] * state_cnt
    children = [[] for _ in range(node_cnt)]
    for p_idx, c_idx in edges:
        children[p_idx].append(c_idx)
        
    stack = list()
    stack.append(1) # init_state = 1 -> root 
    
    while stack:
        cur_state = stack.pop()
        
        if visited[cur_state]:
            continue
        visited[cur_state] = True
        
        cur_sheep = 0
        cur_wolf = 0
        for idx in range(node_cnt):
            if cur_state & (1 << idx):
                if info[idx] == 0:
                    cur_sheep += 1
                else:
                    cur_wolf += 1
        
        if cur_wolf >= cur_sheep:
            continue
            
        answer = max(answer, cur_sheep)
            
        for idx in range(node_cnt):
            if cur_state & (1 << idx):
                for child_idx in children[idx]:
                    nxt_state = cur_state | (1 << child_idx)
                    stack.append(nxt_state)
    
    return answer