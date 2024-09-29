import re
import heapq

def getPlayTime(start_time: str, end_time) -> int:
    start_time_hour, start_time_minute = map(int, start_time.split(":"))
    end_time_hour, end_time_minute = map(int, end_time.split(":"))
    
    return (end_time_hour * 60 + end_time_minute) - (start_time_hour * 60 + start_time_minute)

def getSheet(music: str) -> list:
    ret = []
    for char in music:
        if char == "#":
            ret[-1] = ret[-1] + "#"
        else:
            ret.append(char)
    return ret

def check(m, play_time, sheet):
    if play_time <= len(sheet):
        entire_music = ''.join(sheet[:play_time])
    else:
        entire_music = ''.join(sheet) * (play_time // len(sheet))
        entire_music += ''.join(sheet[:(play_time % len(sheet))])
        
    for s in re.finditer(m, entire_music):
        end_idx = s.end()
        if end_idx < len(entire_music) and entire_music[end_idx] == "#":
            continue
        return True
    
    return False

def solution(m, musicinfos):
    answer = '(None)'
    
    queue = [] # (-play_time, start_time, song_name, sheet)
    
    for musicinfo in musicinfos:
        start_time, end_time, song_name, music = musicinfo.split(",")
        play_time = getPlayTime(start_time, end_time)
        sheet = getSheet(music)
        heapq.heappush(queue, (-play_time, start_time, song_name, sheet))
        
    while queue:
        play_time, _, song_name, sheet = heapq.heappop(queue)
        
        if check(m, -play_time, sheet):
            answer = song_name
            break
            
    return answer