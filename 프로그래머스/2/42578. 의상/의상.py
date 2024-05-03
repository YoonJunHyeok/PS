def solution(clothes):
    closet = {}
    
    for (cloth_name, cloth_type) in clothes:
        if cloth_type in closet:
            closet[cloth_type].append(cloth_name)
        else:
            closet[cloth_type] = [cloth_name]

    answer = 1
    for (cloth_type, cloth_name_list) in closet.items():
        answer = answer * (len(cloth_name_list) + 1)
    answer = answer - 1
    
    return answer