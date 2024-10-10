def get_time(time, process_time):
    hour, minute, second = time.split(":")
    end_time = int(hour) * 60 * 60 * 1000 + int(minute) * 60 * 1000 + float(second) * 1000
    start_time = end_time - float(process_time[:-1]) * 1000 + 1
    
    return (start_time, end_time)

def solution(lines):
    answer = 0
    
    times = []
    for line in lines:
        logs = line.split(" ")
        start_time, end_time = get_time(logs[1], logs[2])
        times.append((start_time, end_time))
        
    for i in range(len(times)):
        tmp = 1
        for j in range(i + 1, len(times)):
            if times[i][1] + 999 >= times[j][0]:
                tmp += 1
                
            if times[j][1] > times[i][1] + 999 + 2999:
                break
                
        answer = max(answer, tmp)
    
    return answer