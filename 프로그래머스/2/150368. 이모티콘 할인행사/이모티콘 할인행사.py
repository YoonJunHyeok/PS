from itertools import product

def solution(users, emoticons):
    answer = []
    n = len(users)
    m = len(emoticons)
    
    for discounts in product([10, 20, 30, 40], repeat=m):
        cur_plus = 0
        cur_sell = 0
        
        for user in users:
            rate_limit, price_limit = user
            cur_user_sell = 0
            
            for discount, emoticon_price in zip(discounts, emoticons):
                if rate_limit > discount:
                    continue
                cur_user_sell += emoticon_price / 100 * (100 - discount)
                
                if cur_user_sell >= price_limit:
                    cur_plus += 1
                    break
            else:
                cur_sell += cur_user_sell
                    
        if len(answer) == 0 or answer[0] < cur_plus or (answer[0] == cur_plus and answer[1] < cur_sell):
            answer = [cur_plus, cur_sell]
    
    return answer