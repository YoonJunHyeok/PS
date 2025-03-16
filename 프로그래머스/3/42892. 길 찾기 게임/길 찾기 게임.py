import sys

sys.setrecursionlimit(10000)
# 전위 순회, 후위 순회를 stack으로 해도, 초기 tree 구성할 때 1000을 넘겨버림
# 1000이하라 했지만, main, solution, setTree 부르면서 1000을 넘기는 듯

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
        
def preOrder(rootIdx):
    global preOrderIdx
    
    stack = list()
    stack.append(rootIdx)
    
    while stack:
        curIdx = stack.pop()
    
        preOrderIdx.append(curIdx + 1)
        for childDir in reversed(range(2)):
            if children[curIdx][childDir] != -1:
                stack.append(children[curIdx][childDir])
    
def postOrder(curIdx):
    global postOrderIdx
    
    stack = list()
    stack.append(curIdx)
    
    while stack:
        curIdx = stack.pop()
        postOrderIdx.append(curIdx + 1)
    
        for childDir in range(2):
            if children[curIdx][childDir] != -1:
                stack.append(children[curIdx][childDir])
                
    postOrderIdx = postOrderIdx[::-1]

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