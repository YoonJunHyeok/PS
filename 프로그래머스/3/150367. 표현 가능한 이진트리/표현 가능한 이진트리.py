from collections import deque

def make_full_binary_tree(bin_number: str):
    total_node = 1
    nxt_leaf_node_cnt = 2
    while total_node < len(bin_number):
        total_node += nxt_leaf_node_cnt
        nxt_leaf_node_cnt *= 2
        
    need_zero_cnt = total_node - len(bin_number)
    added_zeros = ""
    for _ in range(need_zero_cnt):
        added_zeros += "0"
        
    return added_zeros + bin_number

def check(bin_number):
    queue = deque()
    queue.append(bin_number)
    
    while queue:
        cur_bin_number = queue.popleft()
        
        if len(cur_bin_number) == 1:
            continue
            
        mid_idx = len(cur_bin_number) // 2
        left_bin_number = cur_bin_number[:mid_idx]
        right_bin_number = cur_bin_number[mid_idx + 1:]
    
        if cur_bin_number[mid_idx] == "0":
            if any(map(int, list(left_bin_number))) or any(map(int, list(right_bin_number))):
                return False
            else:
                continue
            
        queue.append(left_bin_number)
        queue.append(right_bin_number)

    return True
        

def solve(bin_number):
    full_bin_number = make_full_binary_tree(bin_number)
    
    return check(full_bin_number)

def solution(numbers):
    answer = []
    
    for number in numbers:
        bin_number = bin(number)
        bin_number_str = str(bin_number)
        
        if solve(bin_number_str[2:]):
            answer.append(1)
        else:
            answer.append(0)
    
    return answer