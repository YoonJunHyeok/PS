def solution(n, lost, reserve):    
    filtered_lost = list(set(lost) - set(reserve))
    filtered_lost.sort()
    
    filtered_reserve = set(reserve) - set(lost)
    
    answer = n - len(filtered_lost)
    
    for n in filtered_lost:
        if n-1 in filtered_reserve:
            answer += 1
            filtered_reserve.remove(n-1)
        elif n+1 in filtered_reserve:
            answer += 1
            filtered_reserve.remove(n+1)
    
    return answer