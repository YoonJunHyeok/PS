def is_match(user_id: str, banned_id: str) -> bool:
    if len(user_id) != len(banned_id):
        return False
    
    for u_char, b_char in zip(user_id, banned_id):
        if b_char == '*':
            continue
            
        if u_char != b_char:
            return False
        
    return True

def solution(user_id, banned_id):
    from collections import deque
    
    num_user = len(user_id)
    num_banned = len(banned_id)
    banned_used = [False for _ in range(num_banned)]
    cur_d = deque()
    answer_s = set()
    
    def dfs(user_idx):
        if user_idx == num_user:
            if all(banned_used):
                answer_s.add(tuple(sorted(cur_d)))
            return
        
        for banned_idx in range(num_banned):
            if banned_used[banned_idx]:
                continue
                
            if is_match(user_id[user_idx], banned_id[banned_idx]):
                banned_used[banned_idx] = True
                cur_d.append(user_id[user_idx])
                dfs(user_idx + 1)
                banned_used[banned_idx] = False
                cur_d.pop()
                
        dfs(user_idx + 1)
        
        return

    dfs(0)
                
    answer = len(answer_s)
    
    return answer