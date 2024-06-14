import heapq as hq

def solution(jobs):
    answer = 0
    length = len(jobs)
    
    jobs = [[job[1], job[0]] for job in jobs]
    hq.heapify(jobs)
    
    cur = 0
    while jobs:
        tmp = []
        nxtJob = []
        while jobs:
            job = hq.heappop(jobs)
            if job[1] <= cur:
                nxtJob = job
                break
            else:
                tmp.append(job)
        
        if not nxtJob:
            cur += 1
        else:
            cur += nxtJob[0]
            answer += cur - nxtJob[1]
        
        for t in tmp:
            hq.heappush(jobs, t)
        
    return int(answer/length)