def solution(phone_book):
    answer = True
    
    phone_book.sort()
    
    length = len(phone_book)
    
    for i in range(0, length - 1):
        if phone_book[i + 1].startswith(phone_book[i]):
            answer=False
            break
    
    return answer