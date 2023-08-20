#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    vector<vector<bool>> connected(n + 1, vector<bool> (n + 1, false));
    for(vector<int> edge: edges) {
        connected[edge[0]][edge[1]] = true;
        connected[edge[1]][edge[0]] = true;        
    }
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 2; i <= n; i++) {
            if(connected[cur][i] && dist[i] == -1) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }        
    }
    
    int curMax = -1;
    for(int i  = 2; i <= n; i++) {
        if(dist[i] > curMax) {
            answer = 1;
            curMax = dist[i];
        }
        else if(dist[i] == curMax) {
            answer++;
        }
    }
    
    return answer;
}