def solution(number, k):
    ans = []
    
    for num in number:
        if not ans:
            ans.append(num)
            continue
        while k > 0 and ans and ans[-1] < num:
            ans.pop()
            k -= 1
        ans.append(num)
    
    ans = ans[:-k] if k > 0 else ans
    
    return ''.join(ans)