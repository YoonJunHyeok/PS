from collections import defaultdict
from bisect import bisect_left

class Node:
    def __init__(self):
        self.scores = []
        self.children = defaultdict(Node)
        
class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, infos):
        cur_node = self.root
        
        for info in infos[:-1]:
            cur_node = cur_node.children[info]
            
        idx = bisect_left(cur_node.scores, infos[-1])
        cur_node.scores.insert(idx, infos[-1])
        
    def search(self, querys):
        cur_nodes = [self.root]
        
        for query in querys[:-1]:
            nxt_nodes = []
            
            for cur_node in cur_nodes:
                if query == "-":
                    for nxt_node in cur_node.children.keys():
                        nxt_nodes.append(cur_node.children[nxt_node])
                else:
                    if query in cur_node.children.keys():
                        nxt_nodes.append(cur_node.children[query])
                        
            cur_nodes = nxt_nodes
        
        cnt = 0
        for cur_node in cur_nodes:
            idx = bisect_left(cur_node.scores, querys[-1])                     
            cnt += len(cur_node.scores) - idx
            
        return cnt

def solution(info, query):
    answer = []
    
    trie = Trie()
    for candidate in info:
        candidate_infos = candidate.split()
        candidate_infos[-1] = int(candidate_infos[-1])
        
        trie.insert(candidate_infos)
        
    for q_str in query:
        q = q_str.replace("and", "").split()
        q[-1] = int(q[-1])
        
        answer.append(trie.search(q))
    
    return answer