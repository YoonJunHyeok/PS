from bisect import bisect_left
from collections import deque, defaultdict

class Node:
    def __init__(self):
        self.children = defaultdict(Node)
        self.scores = deque()
        
    def insert(self, score):
        insert_idx = bisect_left(self.scores, score)
        
        self.scores.insert(insert_idx, score)

class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, infos):
        cur_node = self.root
        
        infos_list = list(infos.split(" "))
        score = int(infos_list[-1])
        for info in infos_list[:-1]:
            cur_node = cur_node.children[info]
        cur_node.insert(score)
        
    def search(self, queries):
        queries = queries.replace("and " , "")
        queries_list = list(queries.split(" "))
        base_score = int(queries_list[-1])
        
        stack = deque()
        stack.append(self.root)
        for query in queries_list[:-1]:
            tmp_stack = deque()
            
            while stack:
                cur_node = stack.pop()
                
                if query == "-":
                    for child in cur_node.children.values():
                        tmp_stack.append(child)
                else:
                    if query in cur_node.children:
                        tmp_stack.append(cur_node.children[query])
                        
            stack = tmp_stack
        
        qualified_cnt = 0
        for node in stack:
            scores = node.scores
            disqualified_cnt = bisect_left(scores, base_score)
            
            qualified_cnt += len(scores) - disqualified_cnt
    
        return qualified_cnt

def solution(info, query):
    answer = []
    
    trie = Trie()
    
    for cur_info in info:
        trie.insert(cur_info)
    
    for cur_query in query:
        answer.append(trie.search(cur_query))
    
    return answer