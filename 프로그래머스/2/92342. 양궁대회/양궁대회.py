from itertools import product

def solution(n, info):
    answer = [-1]
    
    max_diff = -1
    
    for ryan_wins in product([0, 1], repeat=11):
        needed_arrows = [info[idx] + 1 if ryan_wins[idx] else 0 for idx in range(11)]
        needed_arrows_cnt = sum(needed_arrows)
        
        if needed_arrows_cnt <= n:
            ryan_score = sum([10 - idx for idx in range(11) if ryan_wins[idx]])
            apeach_score = sum([10 - idx for idx in range(11) if not ryan_wins[idx] and info[idx] > 0])
            
            if ryan_score > apeach_score:
                if needed_arrows_cnt < n:
                    needed_arrows[10] += (n - needed_arrows_cnt)
                
                cur_diff = ryan_score - apeach_score
                
                if cur_diff > max_diff:
                    max_diff = cur_diff
                    answer = needed_arrows.copy()
                elif cur_diff == max_diff:
                    for idx in range(11):
                        if answer[10 - idx] < needed_arrows[10 - idx]:
                            answer = needed_arrows.copy()
                        elif answer[10 - idx] > needed_arrows[10 - idx]:
                            break
    
    return answer