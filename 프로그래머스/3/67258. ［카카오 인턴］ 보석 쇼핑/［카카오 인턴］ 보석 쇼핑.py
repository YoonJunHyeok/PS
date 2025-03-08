from collections import defaultdict

def solution(gems):
    unique_gems = set(gems)
    cur_unique_gems = 0
    gem_count = defaultdict(int)
    end = 0
    min_len = len(gems) + 1
    answer = [1, len(gems)]
    
    for start in range(len(gems)):
        while cur_unique_gems < len(unique_gems) and end < len(gems):
            gem_count[gems[end]] += 1
            if gem_count[gems[end]] == 1:
                cur_unique_gems += 1
            end += 1

        if cur_unique_gems == len(unique_gems) and end - start + 1 < min_len:
            answer = [start + 1, end]
            min_len = end - start + 1
            
        gem_count[gems[start]] -= 1
        if gem_count[gems[start]] == 0:
            cur_unique_gems -= 1
    
    return answer