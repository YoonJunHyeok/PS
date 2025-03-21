from collections import defaultdict

class Node:
    def __init__(self):
        self.children = defaultdict(Node)
        self.cnts = 0 # 이 노드 아래로 단어가 존재하는 개수
        
class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word):
        cur_node = self.root
        
        for c in word:
            cur_node = cur_node.children[c]
            cur_node.cnts += 1
            
    def minimum_search(self, word):
        cur_node = self.root
        
        for idx, c in enumerate(word):
            cur_node = cur_node.children[c]
            
            if cur_node.cnts == 1:
                return idx + 1
        
        return len(word)

def solution(words):
    answer = 0
    
    trie = Trie()
    
    for word in words:
        trie.insert(word)
    
    for word in words:
        answer += trie.minimum_search(word)
    
    return answer