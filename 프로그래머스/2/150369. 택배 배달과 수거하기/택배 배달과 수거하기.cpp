#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<pair<int, int>> d, p;
    for(int i = 0; i < n; i++) {
        if(deliveries[i] != 0) d.push({i + 1, deliveries[i]});
        if(pickups[i] != 0) p.push({i + 1, pickups[i]});
    }
    
    while(!d.empty() || !p.empty()) {
        int maxD = d.empty() ? 0 : d.top().first;
        int maxP = p.empty() ? 0 : p.top().first;
        answer += (long long)(max(maxD, maxP) * 2);
        
        int dbox = 0;
        while(!d.empty() && dbox <= cap) {
            if(dbox + d.top().second <= cap) {
                dbox += d.top().second;
                d.pop();
            }
            else {
                d.top().second -= (cap - dbox);
                break;
            }
        }
        
        int pbox = 0;
        while(!p.empty() && pbox <= cap) {
            if(pbox + p.top().second <= cap) {
                pbox += p.top().second;
                p.pop();
            }
            else {
                p.top().second -= (cap - pbox);
                break;
            }
        }
    }
    
    return answer;
}