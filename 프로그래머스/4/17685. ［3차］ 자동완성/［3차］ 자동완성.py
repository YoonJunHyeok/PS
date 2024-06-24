def lcs(a: str, b: str) :
    ret = 0
    for idx in range(min(len(a), len(b))):
        if a[idx] == b[idx]:
            ret += 1
        else:
            break
            
    return ret

def solution(words):
    answer = 0
    
    words.sort()

    for idx, word in enumerate(words):
        if idx == 0:
            answer += min(len(word), lcs(word, words[idx + 1]) + 1)
        elif idx == len(words) - 1:
            answer += min(len(word), lcs(word, words[idx - 1]) + 1)
        else:
            tmp1 = min(len(word), lcs(word, words[idx - 1]) + 1)
            tmp2 = min(len(word), lcs(word, words[idx + 1]) + 1)
            answer += max(tmp1, tmp2)
    
    return answer