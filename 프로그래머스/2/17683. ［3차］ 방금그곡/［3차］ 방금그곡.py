import re

def get_play_time(start: str, end: str) -> int:
    start_hour, start_minute = map(int, start.split(":"))
    end_hour, end_minute = map(int, end.split(":"))
    
    return (end_hour * 60 + end_minute) - (start_hour * 60 + start_minute)

def solution(m, musicinfos):
    answer = '(None)'
    
    melody_pattern = r'[^#]#?'

    m_list = re.findall(melody_pattern, m)
    
    max_play_time = -1
    for musicinfo in musicinfos:
        start, end, name, melody = musicinfo.split(",")
        
        play_time = get_play_time(start, end)
        melody_list = re.findall(melody_pattern, melody)
        
        loop, leftover = divmod(play_time, len(melody_list))
        total_melody_list = melody_list * loop + melody_list[:leftover]
        
        for idx in range(len(total_melody_list) - len(m_list) + 1):
            if total_melody_list[idx: idx + len(m_list)] == m_list:
                if max_play_time < play_time:
                    answer = name
                    max_play_time = play_time
    
    return answer