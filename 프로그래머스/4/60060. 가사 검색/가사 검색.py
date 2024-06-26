from collections import defaultdict
from bisect import bisect_left, bisect_right

def solution(words, queries):
    answer = []
    
    forward_words, backward_words = defaultdict(list), defaultdict(list)
    
    for word in words:
        length = len(word)
        forward_words[length].append(word)
        backward_words[length].append(word[::-1])
        
    for word_list in forward_words.values():
        word_list.sort()
        
    for word_list in backward_words.values():
        word_list.sort()
        
    for query in queries:
        length = len(query)
        
        aaquery = query.replace('?', 'a')
        zzquery = query.replace('?', 'z')
        
        if query[0] == '?':  
            left = bisect_left(backward_words[length], aaquery[::-1])
            right = bisect_right(backward_words[length], zzquery[::-1])
            answer.append(right-left)
            
        else:
            left = bisect_left(forward_words[length], aaquery)
            right = bisect_right(forward_words[length], zzquery)
            answer.append(right-left)
    
    return answer