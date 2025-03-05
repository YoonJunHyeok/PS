def solution(dartResult):
    answer = 0
    prevScore = None
    curScore = None
    total_len = len(dartResult)
    
    idx = 0
    while idx < total_len:
        c = dartResult[idx]
        
        if c.isnumeric():
            if curScore:
                answer += curScore
                prevScore = curScore     
            
            if c == '1' and dartResult[idx + 1] == '0':
                curScore = 10
                idx += 1
            else:
                curScore = int(c)       
        elif c == 'S':
            pass
        elif c == 'D':
            curScore = pow(curScore, 2)
        elif c == 'T':
            curScore = pow(curScore, 3)
        elif c == '*':
            curScore *= 2
            if prevScore:
                answer += prevScore
        elif c == '#':
            curScore *= -1
            
        idx += 1
            
    answer += curScore
    return answer