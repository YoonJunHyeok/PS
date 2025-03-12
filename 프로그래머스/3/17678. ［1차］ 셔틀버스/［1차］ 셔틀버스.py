import math
import bisect
from collections import defaultdict

def to_minute(s: str) -> int:
    hour, minute = s.split(":")
    
    return int(hour) * 60 + int(minute)

def to_hour(m: int) -> str:
    hour = m // 60
    minute = m % 60
    print(hour, minute)
    
    return str(hour).zfill(2) + ":" + str(minute).zfill(2)

def solution(n, t, m, timetable):
    minutes = list(map(to_minute, timetable))
    minutes.sort()
    
    start_minute = to_minute("09:00")
    last_minute = start_minute + t * (n - 1)
    plans = defaultdict(list)
    
    for minute in minutes:
        if minute < start_minute:
            idx = 0
        elif minute > last_minute:
            continue
        else:
            idx = math.ceil((minute - start_minute) / t)
        
        while idx < n:
            if len(plans[idx]) < m:
                plans[idx].append(minute)
                break
            else:
                idx += 1
                
    
    for idx in range(n):
        if len(plans[idx]) < m:
            answer = start_minute + idx * t
        else:
            for this_minute in reversed(plans[idx]):
                insert_idx = bisect.bisect_right(plans[idx], this_minute - 1)
                if insert_idx < m:
                    answer = this_minute - 1
                    break
                    
    answer = to_hour(answer)
    return answer