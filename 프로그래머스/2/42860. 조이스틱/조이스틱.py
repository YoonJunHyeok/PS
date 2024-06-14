def solution(name):
    answer = 0
    length = len(name)
    min_move = length - 1
    while min_move >= 0 and name[min_move] == 'A':
        min_move -= 1
        
    if min_move < 0:
        return 0
        
    for i, c in enumerate(name):
        answer += min(ord(c) - ord('A'), ord('Z') - ord(c) + 1)
        
        end_A = i + 1
        while end_A < length and name[end_A] == 'A':
            end_A += 1
            
        min_move = min([min_move, i * 2 + (length - end_A), i + (length - end_A) * 2])
    
    answer += min_move    
    
    return answer