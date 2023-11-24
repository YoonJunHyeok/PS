#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool is_corner(int curDir, int nxtDir) {
    return (curDir % 2) != (nxtDir % 2);
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    
    queue<pair<int, pair<int, int>>> q; // {온 방향, {x, y}}
    vector<vector<vector<int>>> cost(N, vector<vector<int>>(N, vector<int>(4, INT_MAX)));
    
    cost[0][0][0] = cost[0][0][1] = cost[0][0][2] = cost[0][0][3] = 0;
    if(board[1][0] == 0) {
        q.push({0, {1, 0}});
        cost[1][0][0] = 100;
    }
    if(board[0][1] == 0) {
        q.push({1, {0, 1}});
        cost[0][1][1] = 100;
    }
    
    while(!q.empty()) {
        auto curInfo = q.front();
        q.pop();
        
        int cur_dir = curInfo.first;
        int curX = curInfo.second.first;
        int curY = curInfo.second.second;
        
        for(int dir = 0; dir < 4; dir++) {
            int nxtX = curX + dx[dir];
            int nxtY = curY + dy[dir];
            
            if(nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N) continue;
            if(board[nxtX][nxtY] == 1) continue;
            
            int weight;
            if(is_corner(cur_dir, dir)) weight = 600;
            else weight = 100;
            
            if(cost[nxtX][nxtY][dir] > cost[curX][curY][cur_dir] + weight) {
                cost[nxtX][nxtY][dir] = cost[curX][curY][cur_dir] + weight;
                q.push({dir, {nxtX, nxtY}});
            }
        }
    }
    
    return min(cost[N - 1][N - 1][0], cost[N - 1][N - 1][1]);
}