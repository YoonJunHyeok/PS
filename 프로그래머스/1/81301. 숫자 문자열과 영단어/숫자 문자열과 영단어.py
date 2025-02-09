def solution(s):    
    words = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    for number, word in enumerate(words):
        s = s.replace(word, str(number))
        
    answer = int(s)
    
    return answer