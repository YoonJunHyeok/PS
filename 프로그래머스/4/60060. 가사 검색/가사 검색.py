from collections import defaultdict

import sys
sys.setrecursionlimit(10**6)

# Trie
class Node(object):
    def __init__(self, key, word=None):
        self.key = key
        self.word = word
        self.cnt = 0
        self.children = {}
        
    def finalize(self):
        self.cnt = 1 if self.word is not None else 0
        for node in self.children.values():
            self.cnt += node.finalize()
            
        return self.cnt
    
class Trie(object):
    def __init__(self):
        self.head = Node(None)
        
    def insert(self, word):
        cur_node = self.head
        
        for char in word:
            if char not in cur_node.children:
                cur_node.children[char] = Node(char)
            cur_node = cur_node.children[char]
    
        cur_node.word = word
        
    def finalize(self):
        self.head.finalize()
        
    def search(self, word):
        cur_node = self.head
        
        for char in word:
            if char == '?':
                break
                
            if char not in cur_node.children:
                return 0
            
            cur_node = cur_node.children[char]
            
        return cur_node.cnt

def solution(words, queries):
    answer = []            
    
    forward_trie, backward_trie = defaultdict(Trie), defaultdict(Trie)
    
    for word in words:
        length = len(word)
        forward_trie[length].insert(word)
        backward_trie[length].insert(word[::-1])
        
    for trie in forward_trie.values():
        trie.finalize()
        
    for trie in backward_trie.values():
        trie.finalize()
        
    for query in queries:
        length = len(query)
        
        if query[0] == '?':
            answer.append(backward_trie[length].search(query[::-1]))
        else:
            answer.append(forward_trie[length].search(query))
    
    return answer