def to_sec(hms: str) -> int:
    hour, minute, second = map(int, hms.split(":"))
    
    return (hour * 60 * 60) + (minute * 60) + second

def to_char(sec: int) -> str:
    hour = (sec // 60) // 60
    minute = (sec // 60) % 60
    second = (sec % 60) % 60
    
    return str(hour).zfill(2) + ":" + str(minute).zfill(2) + ":" + str(second).zfill(2)

def solution(play_time, adv_time, logs):
    play_time_sec = to_sec(play_time)
    adv_time_sec = to_sec(adv_time)
    
    play_cnt = [0] * (play_time_sec + 1)
    
    for log in logs:
        start_hms, end_hms = log.split("-")
        start_sec = to_sec(start_hms)
        end_sec = to_sec(end_hms)
        
        play_cnt[start_sec] += 1
        play_cnt[end_sec] -= 1
        
    for idx in range(1, play_time_sec):
        play_cnt[idx] += play_cnt[idx - 1]
        
    max_cnt = 0
    max_cnt_sec = 0
    cur_cnt = sum(play_cnt[:adv_time_sec])
    
    for idx in range(adv_time_sec - 1, play_time_sec):
        cur_cnt = cur_cnt - play_cnt[idx - adv_time_sec] + play_cnt[idx]
        
        if cur_cnt > max_cnt:
            max_cnt = cur_cnt
            max_cnt_sec = idx - adv_time_sec + 1
        
    answer = to_char(max_cnt_sec)

    return answer