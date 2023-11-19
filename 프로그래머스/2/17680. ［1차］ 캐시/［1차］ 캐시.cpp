#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> cache;
    
    for(string city : cities) {
        
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        bool hit = false;
        int idx = 0;
        while(idx < cache.size()) {
            if(cache[idx] == city) {
                hit = true;
                break;
            }
            idx++;
        }
        
        cache.push_back(city);
        
        if(hit) {
            answer++;
            cache.erase(cache.begin() + idx);
        }
        else {
            answer += 5;
            
            if(cache.size() > cacheSize) {
                cache.pop_front();
            }
        }        
    }
    
    return answer;
}