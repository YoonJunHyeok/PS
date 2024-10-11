def solution(n, info):
    answer = [-1]
    max_diff = -1
    ryan_info = [0]*11
    
    def check():
        ryan_score = 0
        apeach_score = 0
        
        for idx in range(11):
            if ryan_info[idx] == 0 and info[idx] == 0:
                continue
            
            if ryan_info[idx] > info[idx]:
                ryan_score += (10 - idx)
            else:
                apeach_score += (10 - idx)
                
        return (ryan_score > apeach_score, abs(ryan_score - apeach_score))
    
    def dfs(idx, left_arrow):       
        nonlocal answer, max_diff, ryan_info
        
        if idx == 11 or left_arrow == 0:
            can_win, cur_diff = check()
            
            if can_win:
                if left_arrow > 0:
                    ryan_info[10] += left_arrow
                
                if cur_diff > max_diff:
                    answer = ryan_info.copy()
                    max_diff = cur_diff
                elif cur_diff == max_diff:
                    for i in range(11):
                        if ryan_info[10 - i] > answer[10 - i]:
                            answer = ryan_info.copy()
                            break
                        elif answer[10 - i] > ryan_info[10 - i]:
                            break
                            
                if left_arrow > 0:
                    ryan_info[10] -= left_arrow
            return
        elif left_arrow >= info[idx] + 1:
            ryan_info[idx] = info[idx] + 1
            dfs(idx + 1, left_arrow - info[idx] - 1)
            ryan_info[idx] = 0
            
        ryan_info[idx] = 0
        dfs(idx + 1, left_arrow)
        
    dfs(0, n)
    
    return answer