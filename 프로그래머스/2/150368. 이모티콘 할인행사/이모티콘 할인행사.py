from itertools import product

def solution(users, emoticons):
    answer = [0, 0]
    
    available_discounts = [10, 20, 30, 40]
    
    for discounts in product(available_discounts, repeat=len(emoticons)):
        cur_subscribe = 0
        cur_sales = 0
        
        for limit_ratio, limit_price in users:
            buy_price = 0
            for emoticon, discount in zip(emoticons, discounts):
                if discount < limit_ratio:
                    continue
                    
                buy_price += emoticon // 100 * (100 - discount)
                
                if buy_price >= limit_price:
                    cur_subscribe += 1
                    break
            else:
                cur_sales += buy_price  
        
        if cur_subscribe > answer[0]:
            answer = [cur_subscribe, cur_sales]
        elif cur_subscribe == answer[0] and cur_sales > answer[1]:
            answer = [cur_subscribe, cur_sales]
    
    return answer