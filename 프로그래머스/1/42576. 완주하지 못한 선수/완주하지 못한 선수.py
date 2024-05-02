def solution(participant, completion):
    answer = ''
    
    dict = {}
    
    for s in participant:
        if s in dict:
            dict[s] = dict[s] + 1
        else:
            dict[s] = 1
            
    for s in completion:
        dict[s] = dict[s] - 1
    
    for key, value in dict.items():
        if value == 1:
            answer = key
            
    return answer