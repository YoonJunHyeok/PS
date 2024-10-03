from itertools import combinations

def isUnique(relation, comb) -> bool:
    selected_relation = set()
    for row in relation:
        tmp = []
        for idx in comb:
            tmp.append(row[idx])
        selected_relation.add(tuple(tmp))
    
    return len(relation) == len(selected_relation)

def isMinimal(candidateKeys, comb):
    for candidateKey in candidateKeys:
        if set(candidateKey).issubset(set(comb)):
            return False
    return True

def solution(relation):
    candidateKeys = set()
    numOfColumns = len(relation[0])
    columns = [idx for idx in range(numOfColumns)]
    
    for numOfColumn in range(1, numOfColumns + 1):
        combs = combinations(columns, numOfColumn)
        
        for comb in combs:
            if not isUnique(relation, comb):
                continue
                
            if not isMinimal(candidateKeys, comb):
                continue
                
            candidateKeys.add(comb)
    
    return len(candidateKeys)