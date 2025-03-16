def solution(n, build_frame):
    answer = []
    
    gidung = set()
    bo = set()
    
    for x, y, a, b in build_frame:
        if (a, b) == (0, 0):
            # 기둥 삭제
            flag = True
            
            if (x, y + 1) in gidung:
                # 내 위에 다른 기둥 있을 때
                if (x - 1, y + 1) in bo or (x, y + 1) in bo:
                    # 하지만 버틸 수 있는 보가 있을 때
                    pass
                else:
                    flag = False
                    
            if (x - 1, y + 1) in bo:
                # 내 왼쪽 위에 다른 보 있을 때
                if (x - 1, y) in gidung or ((x - 2, y + 1) in bo and (x, y + 1) in bo):
                    # 하지만 버틸 수 있는 기둥이나 보들이 있을 때
                    pass
                else:
                    flag = False
                    
            if (x, y + 1) in bo:
                # 내 오른쪽 위에 다른 보 있을 때
                if (x + 1, y) in gidung or ((x - 1, y + 1) in bo and (x + 1, y + 1) in bo):
                    pass
                else:
                    flag = False
                
            if flag:
                gidung.remove((x, y))
            
        elif (a, b) == (0, 1):
            # 기둥 설치
            if (y == 0) or ((x - 1, y) in bo) or ((x, y) in bo) or ((x, y - 1) in gidung):
                gidung.add((x, y))
            else:
                continue
                
        elif (a, b) == (1, 0):
            # 보 삭제
            flag = True
            
            if (x, y) in gidung:
                # 내 왼쪽 위에 기둥
                if (x, y - 1) in gidung or (x - 1, y) in bo:
                    pass
                else:
                    flag = False
                
            if (x + 1, y) in gidung:
                # 내 오른쪽 위에 기둥
                if (x + 1, y - 1) in gidung or (x + 1, y) in bo:
                    pass
                else:
                    flag = False
                
            if (x - 1, y) in bo:
                # 내 왼쪽에 보
                if (x - 1, y - 1) in gidung or (x, y - 1) in gidung:
                    pass
                else:
                    flag = False
                
            if (x + 1, y) in bo:
                # 내 오른쪽에 보
                if (x + 1, y - 1) in gidung or (x + 2, y - 1) in gidung:
                    pass
                else:
                    flag = False
            
            if flag:
                bo.remove((x, y))
            
        elif (a, b) == (1, 1):
            # 보 설치
            if ((x, y - 1) in gidung) or ((x + 1, y - 1) in gidung) or ((x - 1, y) in bo and (x + 1, y) in bo):
                bo.add((x, y))
            else:
                continue
            
    for gidungX, gidungY in gidung:
        answer.append([gidungX, gidungY, 0])
    for boX, boY in bo:
        answer.append([boX, boY, 1])
    answer.sort()
    
    return answer