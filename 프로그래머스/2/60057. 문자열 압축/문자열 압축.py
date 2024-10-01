def compress(s, n):
    ret = ""
    prev = ""
    cnt = 0
    
    for idx in range(0, len(s), n):
        if prev == s[idx: idx + n]:
            cnt += 1
        else:
            if cnt == 1:
                ret += prev
            elif cnt > 1:
                ret += (str(cnt) + prev)
                
            prev = s[idx: idx + n]
            cnt = 1
            
    if cnt == 1:
        ret += prev
    elif cnt > 1:
        ret += (str(cnt) + prev)
    
    return ret

def solution(s):
    answer = len(s)
    
    for n in range(1, len(s) // 2 + 1):
        answer = min(answer, len(compress(s, n)))
    
    return answer