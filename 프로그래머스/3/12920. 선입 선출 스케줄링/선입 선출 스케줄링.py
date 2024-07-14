def solution(n, cores):    
    if n <= len(cores):
        return n
    
    answer = 0
    
    left, right = 0, max(cores) * n
    
    while left <= right:
        mid = (left + right) // 2
        
        jobs = 0
        for core in cores:
            jobs += (mid // core) + 1
            
            if jobs >= n:
                break
        
        if jobs >= n:
            right = mid - 1
        else:
            left = mid + 1
            
            
    jobs = 0
    for core in cores:
        jobs += (right // core) + 1
        
        
    for idx, core in enumerate(cores):
        if (right + 1) % core == 0:
            jobs += 1
        if jobs == n:
            answer = idx + 1
            break
    
    return answer