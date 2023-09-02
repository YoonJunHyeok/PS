#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> connected(n + 1);
    for(vector<int> road: roads){
        connected[road[0]].push_back(road[1]);
        connected[road[1]].push_back(road[0]);
    }
    vector<int> dist(n+1, -1);
    dist[destination] = 0;
    // destination to all other place
    queue<int> q;
    q.push(destination);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int curDist = dist[cur];
        for(int nxt: connected[cur]) {
            if(dist[nxt] == -1) {
                dist[nxt] = curDist + 1;
                q.push(nxt);
            }
        }
    }
    
    for(int source: sources) {
        answer.push_back(dist[source]);
    }
    return answer;
}