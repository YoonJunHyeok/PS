def solution(genres, plays):
    length = len(genres)
    records = {} # 장르별 (아이디, 재생횟수)의 리스트
    counts = {} # 장르별 재생횟수 카운트
    
    for idx, (genre, play) in enumerate(zip(genres, plays)):
        if genre in records:
            records[genre].append((idx, play))
        else:
            records[genre] = [(idx, play)]
        
        if genre in counts:
            counts[genre] += play
        else:
            counts[genre] = play
    
    answer = []
    
    for genre, _ in sorted(counts.items(), key=lambda x: x[1], reverse=True):
        for idx, _ in sorted(records[genre], key=lambda x: x[1], reverse=True)[:2]:
            answer.append(idx)            
    
    return answer