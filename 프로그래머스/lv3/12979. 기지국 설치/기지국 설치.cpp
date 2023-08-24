#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<pair<int, int>> v;
    
    int idx = 1;
    for(int station: stations) {
        int startIdx = station - w < 1 ? 1 : station - w;
        int endIdx = station + w > n ? n : station + w;
        
        if (idx < startIdx) {
            v.push_back({idx, startIdx - 1});
            idx = endIdx + 1;
        }
        else if (idx >= startIdx) {
            idx = endIdx + 1;
        }        
    }
    
    if(idx <= n) {
        v.push_back({idx, n});
    }
    
    for(int i = 0; i < v.size(); i++){
        int left = v[i].first;
        int right = v[i].second;
        int len = right - left + 1;
        int need = len / (2 * w + 1);
        if(len % (2 * w + 1) != 0) need++;
        
        answer += need;
    }
    
    return answer;
}