def solution(want, number, discount):
    answer = 0
    n = 10
    m = len(discount)
    
    indices = dict()
    for idx, product in enumerate(want):
        indices[product] = idx
        
    for i in range(n):
        if discount[i] in indices:
            number[indices[discount[i]]] -= 1
    
    if not any(number):
        answer += 1
    
    for i in range(n, m):
        if discount[i] in indices:
            number[indices[discount[i]]] -= 1
        if discount[i - n] in indices:
            number[indices[discount[i - n]]] += 1
        
        if not any(number):
            answer += 1
    
    return answer