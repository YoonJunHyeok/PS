import heapq as hq

def solution(operations):
    answer = []
    min_list, max_list = [], []
    cnt = 0
    
    for operation in operations:
        order, num = operation.split()
        num = int(num)
    
        if order == "I":
            hq.heappush(min_list, num)
            hq.heappush(max_list, -num)
            cnt += 1 
        elif order == "D":
            if cnt == 0:
                continue
            
            if num == -1:
                hq.heappop(min_list)
                cnt -= 1
            else:
                hq.heappop(max_list)
                cnt -= 1
        
        if cnt == 0:
            min_list = []
            max_list = []
                
    if cnt == 0:
        answer = [0, 0]
    else:
        answer = [-max_list[0], min_list[0]]
        
    return answer