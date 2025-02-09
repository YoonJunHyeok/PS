def solution(s):
    answer = []
    
    subset_str_list = s[1:-1].split("}")
    subset_list = []
    for ss in subset_str_list:
        if len(ss) == 0:
            continue
            
        if ss[0] == ",":
            ss = ss[1:]
        if ss[0] == "{":
            ss = ss[1:]
            
        num_list = ss.split(",")
        subset_list.append(num_list)
        
    subset_list.sort(key=lambda x: len(x))
    
    num_set = set()
    for ss in subset_list:
        for n in ss:
            if n in num_set:
                continue
            else:
                answer.append(int(n))
                num_set.add(n)
    
    return answer