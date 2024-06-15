from math import sqrt

def solution(brown, yellow):
    answer = []
    
    total = brown + yellow
    for i in range(1, int(sqrt(total)) + 1):
        if total % i != 0: 
            continue
            
        j = int(total / i)
        if (i - 2) * (j - 2) == yellow:
            answer = [j, i]
            break
    
    return answer