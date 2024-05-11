def solution(arr):
    answer = []
    for n in arr:
        if len(answer) == 0 or answer[-1] != n:
            answer.append(n)
    return answer