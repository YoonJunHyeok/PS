#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 }; 
int dy[4] = { 0, 1, 0, -1 };

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> place: places) {        
        int flag = 1;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(place[i][j] != 'P') continue;
                
                queue<pair<int, pair<int, int>>> q; // {현재 이동 거리, {x, y}}
                bool visited[5][5] = { false };
                q.push({0, {i, j}});
                
                while(!q.empty()) {
                    auto curInfo = q.front();
                    q.pop();
                    
                    int dist = curInfo.first;
                    int curX = curInfo.second.first;
                    int curY = curInfo.second.second;
                    visited[curX][curY] = true;
                    
                    if(dist >= 2) continue; // 더 이상 어디 못감
                    
                    for(int dir = 0; dir < 4; dir++) {
                        int nxtX = curX + dx[dir];
                        int nxtY = curY + dy[dir];
                        
                        if(nxtX < 0 || nxtX >= 5 || nxtY < 0 || nxtY >= 5) continue;
                        if(place[nxtX][nxtY] == 'X') continue;
                        if(visited[nxtX][nxtY]) continue;
                        if(place[nxtX][nxtY] == 'P') {
                            flag = 0;
                            break;
                        }
                        
                        q.push({dist + 1, {nxtX, nxtY}});
                    }                    
                    if(!flag) break;
                }                
                if(!flag) break;
            }
            if(!flag) break;
        }
        
        answer.push_back(flag);
    }
    
    return answer;
}