#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50000+1
#define INF 10000000+1

using namespace std;

vector<pair<int, int>> adj[MAX];
bool isSummit[MAX];
int intensity[MAX];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    fill(intensity, intensity+n+2, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(auto path: paths) {
        adj[path[0]].push_back({path[2], path[1]});
        adj[path[1]].push_back({path[2], path[0]});
    }
    for(auto summit: summits) {
        isSummit[summit] = true;
    }
    for(auto gate: gates) {
        intensity[gate] = 0;
        pq.push({0, gate});
    }
    
    while(!pq.empty()) {
        int curIntensity = pq.top().first;
        int curIdx = pq.top().second;
        pq.pop();
        
        if(intensity[curIdx] != curIntensity) continue;
        
        for(auto nxt: adj[curIdx]) {
            int nxtWeight = nxt.first;
            int nxtIdx = nxt.second;
            
            if(intensity[nxtIdx] <= max(curIntensity, nxtWeight)) continue;
            intensity[nxtIdx] = max(curIntensity, nxtWeight);
            
            if(isSummit[nxtIdx]) continue;
            pq.push({intensity[nxtIdx], nxtIdx});
        }
    }
    
    int minIntensity = INF, minIdx;
    sort(summits.begin(), summits.end());
    for(auto summit: summits) {
        if(intensity[summit] < minIntensity) {
            minIntensity = intensity[summit];
            minIdx = summit;
        }
    }
    
    answer.push_back(minIdx);
    answer.push_back(minIntensity);
    
    return answer;
}