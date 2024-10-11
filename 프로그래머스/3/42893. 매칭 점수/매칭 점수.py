import re
from collections import defaultdict

def solution(word, pages):
    answer = 0
    
    word = word.lower()
    page_idx = defaultdict(int) # 링크 별 고유 index 번호
    graph = defaultdict(list) # 자기를 가리키는 링크들의 index의 리스트
    page_basic_scores = [] # page 별 기본 점수
    page_links = [] # 각각의 page 내에 있는 외부 링크들 (list of list)
    
    for idx, page in enumerate(pages):
        page = page.lower()
        
        page_url = re.search(r'<meta property="og:url" content="https://(\S+)"\/>', page).group(1)
        a_links = re.findall(r'<a href="https://(\S+)">', page)
        
        words = re.sub(r'[^a-z]', ' ', page).split()
        basic_score = words.count(word)
        
        page_idx[page_url] = idx
        page_basic_scores.append(basic_score)
        page_links.append(a_links)
    
    for idx, a_links in enumerate(page_links):
        for a_link in a_links:
            if a_link not in page_idx.keys():
                continue
            graph[page_idx[a_link]].append(idx)
            
    max_page_match_score = -1
    for cur_idx in range(len(pages)):
        link_score = 0
        for link_idx in graph[cur_idx]:
            link_score += page_basic_scores[link_idx] / len(page_links[link_idx])
        
        match_score = page_basic_scores[cur_idx] + link_score

        if match_score > max_page_match_score:
            max_page_match_score = match_score
            answer = cur_idx
    
    return answer