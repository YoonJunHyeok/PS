def solution(routes):
    answer = 0
    
    for route in routes:
        if route[0] > route[1]:
            route[0], route[1] = route[1], route[0]
            
    routes.sort(key=lambda x: x[1])
    
    idx = 0
    length = len(routes)
    while idx < length:
        end = routes[idx][1]
        
        idx += 1
        while idx < length and routes[idx][0] <= end:
            idx += 1
        
        answer += 1

    return answer