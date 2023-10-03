#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 1, n;
vector<int> l, r, v;
bool vis[1 << 17];

void track(int state) {
    if(vis[state]) return;
    vis[state] = true;
    
    int curWolf = 0, curSheep = 0;
    for(int i = 0; i < n; i++) {
        if(state & (1 << i)) {
            // i번째 노드 방문했다는 의미
            if(v[i]) curWolf++;
            else  curSheep++;
        }
    }
    
    if(curWolf >= curSheep) return;
    
    answer = max(answer, curSheep);
    
    for(int i = 0; i < n; i++) {
        if(state & (1 << i)) {
            if(l[i] != -1) {
                track(state | (1 << l[i]));
            }
            
            if(r[i] != -1) {
                track(state | (1 << r[i]));
            }
        }
    }    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    l = r = vector<int> (n, -1);
    v = info;
    for(vector<int> edge: edges) {
        if(l[edge[0]] == -1) l[edge[0]] = edge[1];
        else r[edge[0]] = edge[1];
    }
    
    track(1); // 0...01로 시작
    
    return answer;
}