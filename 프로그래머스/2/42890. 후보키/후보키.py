from itertools import combinations

def solution(relation):
    row_len = len(relation)
    column_len = len(relation[0])
    candidates = list(range(column_len))
    
    candidate_keys = list()
    
    for step in range(1, column_len + 1):
        for column_idxs in combinations(candidates, step):
            flag = False
            column_idxs_str = "".join(list(map(str, column_idxs)))
            for candidate_key in candidate_keys:
                if all(c in column_idxs_str for c in candidate_key):
                    flag = True
                    break
                    
            if flag:
                continue
            
            s = set()
            for row_idx in range(row_len):
                row = []
                for column_idx in column_idxs:
                    row.append(relation[row_idx][column_idx])
                    
                s.add(tuple(row))
            
            if len(s) == row_len:
                candidate_keys.append(column_idxs_str)
            
    answer = len(candidate_keys)
    
    return answer