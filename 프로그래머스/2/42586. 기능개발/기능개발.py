import math

def solution(progresses, speeds):
    answer = []
    
    day = 0
    cnt = 0
    for progress, speed in zip(progresses, speeds):
        if progress + speed * day >= 100:
            cnt += 1
        else:
            if cnt > 0:
                answer.append(cnt)
                cnt = 0
            left_progress = 100 - (progress + speed * day)
            add_day = math.ceil(left_progress / speed)
            day += add_day
            cnt += 1
    
    answer.append(cnt)
    
    return answer