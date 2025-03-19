def solution(food_times, k):
    answer = 0
    
    left_food_cnt = len(food_times) # 남은 양이 0이 아닌 음식
    cycle_cnt = 0 # 사이클 돌린 횟수
    
    food_with_idx = [[idx + 1, f] for idx, f in enumerate(food_times)]
    food_orderby_amount_asc = sorted(food_with_idx, key=lambda x: x[1])
    
    for idx, (origin_idx, food_amount) in enumerate(food_orderby_amount_asc):
        cur_left_food_amount = food_amount - cycle_cnt
        
        if left_food_cnt <= 0:
            # 앞에 같은 양의 음식이 있어서, 앞에서 이미 처리한 내용.
            left_food_cnt -= 1
            continue
        
        if k - (left_food_cnt * cur_left_food_amount) < 0:
            break
        else:
            k = k - (left_food_cnt * cur_left_food_amount)
            left_food_cnt -= 1
            cycle_cnt += cur_left_food_amount
            food_orderby_amount_asc[idx][1] = 0
    
    if left_food_cnt <= 0:
        return -1
            
    k = k % left_food_cnt
    food_orderby_idx_asc = sorted(food_orderby_amount_asc, key=lambda x: x[0])
    
    for idx, left_food_amount in food_orderby_idx_asc:
        if left_food_amount > 0:
            if k == 0:
                answer = idx
                break   
            else:
                k -= 1
        else:
             continue   
    
    return answer