#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    // init
    int lockSize = lock.size();
    int keySize = key.size();
    int total_hole = 0;
    int rootX = -1, rootY = -1;
    for(int i = 0; i < lockSize; i++) {
        for(int j = 0; j < lockSize; j++) {
            if(lock[i][j] == 0) {
                total_hole++;
                if(rootX == -1 && rootY == -1) {
                    rootX = i;
                    rootY = j;
                }
            }
        }
    }
    
    vector<pair<int, int>> key_hole;
    for(int i = 0; i < keySize; i++) {
        for(int j = 0; j < keySize; j++) {
            if(key[i][j] == 1) {
                key_hole.push_back({i, j});
            }
        }
    }
    int keyNum = key_hole.size();
    
    // cal
    bool flag = false;
    for(int rotate = 0; rotate < 4; rotate++) {
        for(int idx = 0; idx < keyNum; idx++) {
            // rootX와 rootY에 key_hole[idx]를 위치시킨다.
            int dx = key_hole[idx].first, dy = key_hole[idx].second;
            int curCnt = 0;
            for(int i = 0; i < keyNum; i++) {
                int curX = key_hole[i].first - dx + rootX;
                int curY = key_hole[i].second - dy + rootY;
                if(curX < 0 || curX >= lockSize || curY < 0 || curY >= lockSize) continue;
                if(lock[curX][curY] == 1) {
                    curCnt = -1;
                    break;
                }
                curCnt++;                
            }
            
            if(curCnt == total_hole) {
                flag = true;
                break;
            }
        }
        
        if(flag) break;
        else {
            // 전체 90도 회전
            for(int i = 0; i < keyNum; i++) {
                int tmp = key_hole[i].first;
                key_hole[i].first = key_hole[i].second;
                key_hole[i].second = keySize - tmp - 1;
            }
        }
    }
    
    answer = flag;
    
    return answer;
}