def solution(n, words):
    answer = []
    used = set()
    
    for idx, word in enumerate(words):
        if idx == 0:
            used.add(word)
            continue
        
        if words[idx - 1][-1] != word[0] or word in used:
            answer.append(idx % n + 1)
            answer.append(idx // n + 1)
            break
        else:
            used.add(word)
            
    if len(answer) == 0:
        answer.append(0)
        answer.append(0)
    
    return answer