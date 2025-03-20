from itertools import permutations

def get_dist(cur_idx, nxt_idx, n):
    if nxt_idx > cur_idx:
        return nxt_idx - cur_idx
    else:
        return (n - cur_idx) + (nxt_idx)

def solution(n, weak, dist):
    answer = len(dist) + 1
    
    weak_len = len(weak)
    weak2 = weak + weak
    
    for cur_dist in permutations(dist):
        for start_idx in range(weak_len):
            cur_idx = start_idx
        
            for friend_idx, max_move in enumerate(cur_dist):
                cur_move = 0

                while cur_idx < start_idx + weak_len:
                    nxt_dist = get_dist(weak2[cur_idx], weak2[cur_idx + 1], n)

                    if cur_move + nxt_dist > max_move:
                        break
                    else:
                        cur_idx += 1
                        cur_move += nxt_dist

                cur_idx += 1 # cur_idx까지 처리했으니, 다음부터 보라고 1 더해줌.

                if cur_idx >= start_idx + weak_len:
                    # 한 바퀴 돌았음
                    answer = min(answer, friend_idx + 1)
                    break
                    
            
    if answer == len(dist) + 1:
        answer = -1
    
    return answer