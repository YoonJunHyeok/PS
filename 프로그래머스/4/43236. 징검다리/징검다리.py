def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    
    start = 1
    end = distance
    while start <= end:
        middle = (start + end) // 2
        
        cnt = 0
        prev_rock = 0
        for rock in rocks:
            if rock - prev_rock >= middle:
                prev_rock = rock
            else:
                # middle이 거리의 최솟값이 될 수 있게, 현재 'rock'은 제거해줘야함
                cnt += 1
                
        if distance - prev_rock < middle:
            cnt += 1
        
        if cnt <= n:
            # 최대 n개의 바위를 제거하면서 최솟값 middle 달성 가능
            answer = middle
            # 최솟값 늘려보기
            start = middle + 1
        else:
            # 달성 불가능, n개보다 더 제거해줘야함
            end = middle - 1
    
    return answer