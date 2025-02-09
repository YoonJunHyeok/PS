def solution(n, arr1, arr2):
    answer = []
    
    for num1, num2 in zip(arr1, arr2):
        line_num = num1 | num2
        line_str = ""
        
        for _ in range(n):
            line_str = "#" + line_str if line_num % 2 == 1 else " " + line_str
            line_num = line_num // 2
        
        answer.append(line_str)
    
    return answer