#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<string> board) {
    int answer = -1, rX, rY, gX, gY;
    int row = board.size(), column = board[0].length();
    
    vector<vector<int>> cost(row, vector<int>(column, -1));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(board[i][j] == 'R') {
                rX = i;
                rY = j;
                cost[i][j] = 0;
            }
            if(board[i][j] == 'G') {
                gX = i;
                gY = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({rX, rY});
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.first == gX && cur.second == gY) {
            answer = cost[gX][gY];
            break;
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nxtX = cur.first, nxtY = cur.second;
            while(1) {
                if(nxtX + dx[dir] < 0 || nxtX + dx[dir] >= row || nxtY + dy[dir] < 0 || nxtY + dy[dir] >= column) break;
                if(board[nxtX + dx[dir]][nxtY + dy[dir]] == 'D') break;
                nxtX += dx[dir];
                nxtY += dy[dir];
            }
            
            if(cost[nxtX][nxtY] != -1) continue;
            cost[nxtX][nxtY] = cost[cur.first][cur.second] + 1;
            q.push({nxtX, nxtY});
        }
    }
    
    return answer;
}