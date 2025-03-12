import math

def solution(s):
    if len(s) == 1:
        return 1
    
    answer = 1001
    
    max_token_len = len(s) // 2
    
    for token_len in range(1, max_token_len + 1):
        accum_cnt = 0
        accum_str = ""
        result = ""
        
        for idx in range(math.ceil(len(s) / token_len)):
            cur_str = s[idx*token_len:(idx+1)*token_len]
            print
            if accum_str == cur_str:
                accum_cnt += 1
            else:
                if accum_cnt > 1:
                    result = result + str(accum_cnt) + accum_str
                else:
                    result += accum_str
                accum_cnt = 1
                accum_str = cur_str
                
        if accum_cnt > 1:
            result = result + str(accum_cnt) + accum_str
        else:
            result += accum_str
            
        answer = min(answer, len(result))
    
    return answer