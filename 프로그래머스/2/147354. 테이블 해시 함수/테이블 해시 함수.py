def getXOR(data):
    ret = data[0]
    for v in data[1:]:
        ret = ret ^ v
        
    return ret

def getS(data):
    s_data = []
    for idx, row in enumerate(data):
        s = sum(v % (idx + 1) for v in row)
        s_data.append(s)
        
    return s_data

def solution(data, col, row_begin, row_end):
    answer = 0
    
    sorted_data = sorted(data, key = lambda x: (x[col - 1], -x[0]))
    s_data = getS(sorted_data)
    answer = getXOR(s_data[row_begin - 1: row_end])
    
    return answer