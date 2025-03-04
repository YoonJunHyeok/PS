def solution(msg):
    answer = []
    indices = {}
    for i, c in enumerate(range(ord('A'), ord('Z') + 1), start=1):
        indices[chr(c)] = i
        
    total_len = len(msg)
    start = 0
    end = 1
    while True:
        ans_index = -1
        while end <= total_len and msg[start:end] in indices:
            ans_index = indices[msg[start:end]]
            end += 1
            
        answer.append(ans_index)
        
        if end > total_len:
            break
        else:
            indices[msg[start:end]] = len(indices) + 1
            start = end - 1
    
    return answer