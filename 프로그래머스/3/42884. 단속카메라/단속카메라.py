def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])
    
    last_out = -30001
    for route in routes:
        if route[0] > last_out:
            answer += 1
            last_out = route[1]

    return answer