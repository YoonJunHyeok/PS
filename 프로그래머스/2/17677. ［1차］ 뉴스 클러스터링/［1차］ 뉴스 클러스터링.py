from collections import Counter

def seperate(s):
    length = len(s)

    substr_list = list()    
    for idx in range(length - 1):
        substr = s[idx: idx + 2]
        
        if substr.isalpha():
            substr_list.append(substr)
            
    return Counter(substr_list)
        

def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    
    substr1_counter = seperate(str1)
    substr2_counter = seperate(str2)
    
    if len(substr1_counter) == 0 and len(substr2_counter) == 0:
        answer = 1 * 65536
    else:
        intersection_score = 0
        union_score = 0

        for substr1 in substr1_counter:
            if substr1 in substr2_counter:
                intersection_score += min(substr1_counter[substr1], substr2_counter[substr1])
                union_score += max(substr1_counter[substr1], substr2_counter[substr1])
            else:
                union_score += substr1_counter[substr1]

        for substr2 in substr2_counter:
            if substr2 not in substr1_counter:
                union_score += substr2_counter[substr2]
        
        answer = int(intersection_score / union_score * 65536)
        
    return answer