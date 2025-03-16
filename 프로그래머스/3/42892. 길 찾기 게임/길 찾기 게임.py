import sys

sys.setrecursionlimit(10 ** 6)

def setTree(parentIdx, childInfo):
    global children, nodeX
    
    childX, childY, childIdx = childInfo
    parentX = nodeX[parentIdx]
    
    childDir = 0 if childX < parentX else 1
    
    if children[parentIdx][childDir] == -1:
        children[parentIdx][childDir] = childIdx
        return
    else:
        setTree(children[parentIdx][childDir], childInfo)
        
def preOrder(curIdx):
    global preOrderIdx
    
    preOrderIdx.append(curIdx + 1)
    for childDir in range(2):
        if children[curIdx][childDir] != -1:
            preOrder(children[curIdx][childDir])
    
def postOrder(curIdx):
    global postOrderIdx
    
    for childDir in range(2):
        if children[curIdx][childDir] != -1:
            postOrder(children[curIdx][childDir])
            
    postOrderIdx.append(curIdx + 1)

def solution(nodeinfo):
    global children, nodeX, preOrderIdx, postOrderIdx
    
    children = [[-1, -1] for _ in range(len(nodeinfo))]
    nodeX = [x for [x, _] in nodeinfo]
    nodeinfos = [[-y, x, idx] for idx, [x, y] in enumerate(nodeinfo)]
    nodeinfos.sort()
    
    rootIdx = nodeinfos[0][2]
    for my, x, idx in nodeinfos[1:]:
        y = -my
        setTree(rootIdx, (x, y, idx))
    
    answer = list()
    
    preOrderIdx = list()
    preOrder(rootIdx)
    answer.append(preOrderIdx)
    
    postOrderIdx = list()
    postOrder(rootIdx)
    answer.append(postOrderIdx)
    
    return answer