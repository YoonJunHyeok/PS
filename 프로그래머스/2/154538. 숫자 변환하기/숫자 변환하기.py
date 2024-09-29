def solution(x, y, n):
    answer = 0
    s = set([x])
    
    while s:
        if y in s:
            return answer
        
        ns = set()
        for cur in s:
            if cur + n <= y:
                ns.add(cur + n)
            if cur * 2 <= y:
                ns.add(cur * 2)
            if cur * 3 <= y:
                ns.add(cur * 3)
        s = ns
        answer += 1
    
    return -1