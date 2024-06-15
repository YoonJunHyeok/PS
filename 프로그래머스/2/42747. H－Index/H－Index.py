def solution(citations):
    answer = 0
    length = len(citations)
    
    citations.sort()
    for idx in range(length):
        if citations[idx] >= length - idx:
            answer = length - idx
            break
    
    return answer