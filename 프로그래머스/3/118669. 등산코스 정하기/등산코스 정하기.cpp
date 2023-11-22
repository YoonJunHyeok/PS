#include <string>
#include <vector>
#include <queue>
#define INF 10000000+1
#define MAX 50000+1

using namespace std;

vector<pair<int, int>> routes[MAX];
vector<bool> isSummit;
vector<int> cgates, intensity;

pair<int, int> dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int minSummit = INF, minIntensity = INF;
    
    for(int gate: cgates) {
        pq.push({0, gate});
        intensity[gate] = 0;
    }
    
    while(!pq.empty()) {
        int curIntensity = pq.top().first;
        int curIdx = pq.top().second;
        pq.pop();
        
        if(intensity[curIdx] < curIntensity) continue;
        
        if(isSummit[curIdx]) {
            if(curIntensity <= minIntensity) {
                if(curIntensity == minIntensity) {
                    minSummit = min(minSummit, curIdx);
                }
                else {
                    minSummit = curIdx;
                }
                minIntensity = curIntensity;
            }
            continue;
        }
        
        for(pair<int, int> route: routes[curIdx]) {
            int nxtIntensity = route.first;
            int nxtIdx = route.second;
            int curMaxIntensity = max(curIntensity, nxtIntensity);
            
            if(intensity[nxtIdx] == INF || curMaxIntensity < intensity[nxtIdx]) {
                intensity[nxtIdx] = curMaxIntensity;
                pq.push({curMaxIntensity, nxtIdx});
            }
        }
    }
    
    return {minSummit, minIntensity};
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    intensity = vector<int>(n + 1, INF);
    
    for(vector<int> path: paths) {
        routes[path[0]].push_back({path[2], path[1]});
        routes[path[1]].push_back({path[2], path[0]});
    }
    
    isSummit = vector<bool>(n + 1, false);
    for(int summit: summits) {
        isSummit[summit] = true;
    }
    
    cgates = gates;
    
    pair<int, int> res = dijkstra();
    answer.push_back(res.first);
    answer.push_back(res.second);
    
    return answer;
}