#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    int weakCnt = weak.size();
    int friendCnt = dist.size();
    
    for(int i = 0; i < weakCnt - 1; i++) {
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end());
    
    
    do {
        for(int i = 0; i < weakCnt; i++) {
            int start = weak[i];
            int end = weak[i + weakCnt - 1];
            
            for(int j = 0; j < friendCnt; j++) {
                start += dist[j];
                
                if(start >= end) {
                    answer = min(answer, j + 1);
                    break;
                }
                
                for(int k = i + 1; k < i + weakCnt; k++) {
                    if(weak[k] > start) {
                        start = weak[k];
                        break;
                    }
                }
            }
        }        
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 9) answer = -1;
    return answer;
}