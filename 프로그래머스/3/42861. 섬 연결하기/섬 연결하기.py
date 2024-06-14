parents = []
def Find(x):
    global parents
    if parents[x] == x:
        return x
    else:
        p = Find(parents[x])
        parents[x] = p
        return p

def Union(x, y):
    global parents
    x = Find(x)
    y = Find(y)
    
    if x < y:
        parents[y] = x
    else:
        parents[x] = y

def solution(n, costs):
    global parents
    parents = list(range(n))
    
    answer = 0
    
    costs.sort(key=lambda x: x[2])
    
    for x, y, cost in costs:
        if Find(x) == Find(y):
            continue
        else:
            Union(x, y)
            answer += cost
    
    return answer