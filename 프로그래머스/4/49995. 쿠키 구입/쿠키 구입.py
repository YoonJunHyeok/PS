def solution(cookie):
    answer = 0
    
    length = len(cookie)
    
    for m in range(length - 1):
        left_idx, right_idx = m, m + 1
        left_sum = cookie[left_idx]
        right_sum = cookie[right_idx]
        
        while True:
            if left_sum == right_sum and answer < left_sum:
                answer = left_sum
            
            if left_sum <= right_sum and left_idx > 0:
                left_idx -= 1
                left_sum += cookie[left_idx]
            elif left_sum > right_sum and right_idx < length - 1:
                right_idx += 1
                right_sum += cookie[right_idx]
            else:
                break
    
    return answer