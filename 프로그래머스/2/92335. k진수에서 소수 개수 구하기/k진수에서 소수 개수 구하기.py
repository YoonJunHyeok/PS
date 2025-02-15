def convert(n: int, k: int) -> str:
    ret = ""
    
    while n:
        ret = str(n % k) + ret
        n //= k
        
    return ret

def isPrime(n: int) -> bool:
    if n == 1:
         return False
    
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    
    n_by_k = convert(n, k)
    
    nums = n_by_k.split("0")
    for num in nums:
        if num == '':
            continue
            
        if isPrime(int(num)):
            answer += 1
    
    return answer