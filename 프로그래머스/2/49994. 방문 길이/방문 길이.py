def align(ax, ay, bx, by):
    if ax == bx:
        return (ax, ay, bx, by) if ay < by else (bx, by, ax, ay)
    else:
        return (ax, ay, bx, by) if ax < bx else (bx, by, ax, ay)

def isout(x, y):
    if x < -5 or x > 5 or y < -5 or y > 5:
        return True
    return False

def solution(dirs):
    dxdy = {
        "U": (0, 1),
        "D": (0, -1),
        "R": (1, 0),
        "L": (-1, 0)
    }
    
    visited = set()
    curx = 0
    cury = 0
    
    for dir in dirs:
        (dx, dy) = dxdy.get(dir)
        
        nxtx = curx + dx
        nxty = cury + dy
        
        if isout(nxtx, nxty):
            continue
            
        visited.add(align(curx, cury, nxtx, nxty))
        curx = nxtx
        cury = nxty
    
    answer = len(visited)
    return answer