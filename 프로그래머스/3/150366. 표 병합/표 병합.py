def solution(commands):
    answer = []
    parents = [idx for idx in range(2500)]
    board = ["EMPTY"]*2500
    
    def find(x):
        if parents[x] != x:
            parents[x] = find(parents[x])
        return parents[x]
    
    def union(x, y):
        x = find(x)
        y = find(y)
        
        parents[y] = x
            
    for command_str in commands:
        command = command_str.split()
        command_type = command[0]
        
        if command_type == "UPDATE":
            if len(command) == 4:
                r = int(command[1]) - 1
                c = int(command[2]) - 1
                new_v = command[3]
                
                cur_idx = r * 50 + c
                p_idx = find(cur_idx)
                board[p_idx] = new_v
            elif len(command) == 3:
                v1 = command[1]
                v2 = command[2]
                
                board = [v2 if v == v1 else v for v in board]
        elif command_type == "MERGE":
            r1 = int(command[1]) - 1
            c1 = int(command[2]) - 1
            r2 = int(command[3]) - 1
            c2 = int(command[4]) - 1
            
            idx1 = r1 * 50 + c1
            idx2 = r2 * 50 + c2
            
            p_idx1 = find(idx1)
            p_idx2 = find(idx2)
            
            if board[p_idx1] == "EMPTY" and board[p_idx2] != "EMPTY":
                union(idx2, idx1)
            else:
                union(idx1, idx2)
                
            p_idx = find(idx1)
            for idx in range(2500):
                if find(idx) in [p_idx1, p_idx2]:
                    parents[idx] = p_idx
                    
        elif command_type == "UNMERGE":
            r = int(command[1]) - 1
            c = int(command[2]) - 1
            
            cur_idx = r * 50 + c
            p_idx = find(cur_idx)
            cur_v = board[p_idx]
            
            for idx in range(2500):
                if find(idx) == p_idx:
                    parents[idx] = idx
                    board[idx] = "EMPTY"
            board[cur_idx] = cur_v
        else:
            r, c = int(command[1]) - 1, int(command[2]) - 1
            idx = r * 50 + c
            p_idx = find(idx)
            answer.append(board[p_idx])
    return answer