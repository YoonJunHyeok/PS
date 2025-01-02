def solution(n, left, right):
    answer = []
    
    for idx in range(left, right + 1):
        column_idx = idx // n
        row_idx = idx % n
        answer.append(max(column_idx, row_idx) + 1)
    
    return answer