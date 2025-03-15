from itertools import product

def rotate(key, num):
    if num == 0:
        return key
    
    M = len(key)
    
    ret_key = [[0] * M for _ in range(M)]
    
    for i, j in product(range(M), repeat=2):
        ret_key[j][M - i - 1] = key[i][j]

    return rotate(ret_key, num - 1)

def is_out(i, j, N):
    if i < 0 or i >= N or j < 0 or j >= N:
        return True
    return False

def solution(key, lock):
    N = len(lock)
    M = len(key)
    
    home_cnt = N * N - sum(sum(lock, []))
    if home_cnt == 0:
        return True
    
    keys = list(rotate(key, num) for num in range(4))
    
    for sync_idx in product(range(1 - M, N), repeat=2):
        row_sync_idx, column_sync_idx = sync_idx
        
        for cur_key in keys:
            cur_home_cnt = 0
            for key_i, key_j in product(range(M), repeat=2):
                lock_i = key_i + row_sync_idx
                lock_j = key_j + column_sync_idx
                
                if is_out(lock_i, lock_j, N):
                    continue
                    
                if lock[lock_i][lock_j] == 1:
                    if cur_key[key_i][key_j] == 1:
                        break
                    elif cur_key[key_i][key_j] == 0:
                        pass
                elif lock[lock_i][lock_j] == 0:
                    if cur_key[key_i][key_j] == 1:
                        cur_home_cnt += 1
                    elif cur_key[key_i][key_j] == 0:
                        break
            else:
                if cur_home_cnt == home_cnt:
                    return True
                
    
    return False