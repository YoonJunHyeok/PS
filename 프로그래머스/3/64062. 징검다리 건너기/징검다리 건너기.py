def is_possible(stones: list, friends: int, max_jump: int) -> bool:
    cur_jump = 1
    for stone in stones:
        if cur_jump > max_jump:
            return False
        
        if stone < friends:
            cur_jump += 1
        else:
            cur_jump = 1
        
    if cur_jump > max_jump:
        return False
    return True

def solution(stones, k):
    answer = 0
    
    start, end = 0, max(stones)
    
    while start <= end:
        mid = (start + end) // 2
        
        if is_possible(stones, friends=mid, max_jump=k):
            start = mid + 1
            answer = mid
        else:
            end = mid - 1
    
    return answer