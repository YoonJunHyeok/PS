from math import ceil

def solution(n, times):
    answer = 0
    
    left = 1
    right = ceil(max(times) * n / len(times))
    
    while left <= right:
        mid = (left + right) // 2
        
        available = sum(list(map(lambda x: mid // x, times)))
        
        if available >= n:
            right = mid - 1
            answer = mid
        else:
            left = mid + 1
    
    return answer