import math
from collections import defaultdict

def get_parking_time(start_time: str, end_time: str) -> int:
    start_hour, start_minute = map(int, start_time.split(":"))
    end_hour, end_minute = map(int, end_time.split(":"))
    
    return (end_hour * 60 + end_minute) - (start_hour * 60 + start_minute)

def get_parking_fee(parking_time: int, fees: list) -> int:
    base_time, base_fee, unit_time, unit_fee = fees
    
    if parking_time <= base_time:
        return base_fee
    
    return base_fee + math.ceil((parking_time - base_time) / unit_time) * unit_fee


def solution(fees, records):    
    d = {} # 차량 번호: 입차 시간
    total_parking_time = defaultdict(int) # 차량 번호: 총 이용 시간
    for record in records:
        time, car, record_type = record.split(" ")
        
        if record_type == "IN":
            d[car] = time
            continue
             
        start_time = d[car]
        end_time = time
        cur_parking_time = get_parking_time(start_time, end_time)
        
        total_parking_time[car] += cur_parking_time
        d.pop(car)
    
    for car, start_time in d.items():
        end_time = "23:59"
        cur_parking_time = get_parking_time(start_time, end_time)
        
        total_parking_time[car] += cur_parking_time
        
    answer = []
    for car, parking_time in sorted(total_parking_time.items()):
        answer.append(get_parking_fee(parking_time, fees))
    
    return answer