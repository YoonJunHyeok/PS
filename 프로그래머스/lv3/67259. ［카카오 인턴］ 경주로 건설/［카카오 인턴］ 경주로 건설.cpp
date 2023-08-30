#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = INT_MAX;

bool is_corner(int cur_dir, int next_dir) {
    if(cur_dir % 2 == 0) {
        if(next_dir % 2 == 0) return false;
        else return true;
    }
    else {
        if(next_dir % 2 == 0) return true;
        else return false;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    vector<vector<vector<int>>> costs(N, vector<vector<int>> (N, vector<int> (4, INF)));
    queue<pair<int, pair<int, int>>> q;
    // first int: dir -> 0, 1, 3, 4
    
    costs[0][0][0] = costs[0][0][1] = costs[0][0][2] = costs[0][0][3] = 0;
    if(board[0][1] == 0) {
        q.push({1, {0, 1}});
        costs[0][1][1] = 1;
    }
    if(board[1][0] == 0) {
        q.push({0, {1, 0}});
        costs[1][0][0] = 1;
    }
    
    while(!q.empty()) {
        pair<int, pair<int, int>> tmp = q.front();
        q.pop();
        int dir = tmp.first;
        int curx = tmp.second.first;
        int cury = tmp.second.second;
        int curCost = costs[curx][cury][dir];
        
        for(int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(board[nx][ny] == 1) continue;
            
            int tmpCost;
            if(dir == -1 || !is_corner(dir, i)) {
                tmpCost = curCost + 1;
            }
            else if(is_corner(dir, i)) {
                tmpCost = curCost + 6;
            }
            
            if(tmpCost < costs[nx][ny][i]) {
                costs[nx][ny][i] = tmpCost;
                q.push({i, {nx, ny}});
            }
        }
    }
    
    answer = min(costs[N - 1][N - 1][0], costs[N - 1][N - 1][1]) * 100;
    
    return answer;
}