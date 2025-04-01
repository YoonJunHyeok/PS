from collections import Counter

def solution(k, tangerine):
    size_count = Counter(tangerine)
    
    counts_desc = sorted(size_count.values(), reverse=True)
    
    total = 0
    for idx, cnt in enumerate(counts_desc):
        total += cnt
        
        if total >= k:
            return idx + 1