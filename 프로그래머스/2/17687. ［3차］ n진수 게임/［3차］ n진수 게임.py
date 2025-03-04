def convert(num: int, base: int) -> str:
    if num == 0:
        return '0'
    
    ret = ''
    over_nine = ['A', 'B', 'C', 'D', 'E', 'F']
    while num:
        leftover = num % base
        if leftover < 10:
            ret = str(leftover) + ret
        else:
            ret = over_nine[leftover - 10] + ret
            
        num //= base
        
    return ret

def solution(n, t, m, p):
    total_string = ''
    cur_num = 0
    
    while len(total_string) < t * m:
        total_string = total_string + convert(cur_num, n)
        cur_num += 1  
        
    answer = ''
    for _ in range(t):
        answer += total_string[p - 1]
        p += m
        
    return answer