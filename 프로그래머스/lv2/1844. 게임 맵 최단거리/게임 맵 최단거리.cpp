#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 99999;
vector<vector<int>> board;
queue<pair<int, int>> worklist;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> maps) {
    int answer, N = maps.size(), M = maps[0].size();
    for(int i = 0; i < N; i++) {
        board.push_back(vector<int> (M, INF));
    }
    board[0][0] = 1;
    worklist.push({0, 0});
    
    while(!worklist.empty()) {
        int curx, cury;
        tie(curx, cury) = worklist.front(); worklist.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(!maps[nx][ny] || board[nx][ny] <= board[curx][cury] + 1) continue;
            board[nx][ny] = board[curx][cury] + 1;
            worklist.push({nx, ny});
        }
    }
    
    if (board[N - 1][M - 1] == INF) answer = -1;
    else answer = board[N - 1][M - 1];
    return answer;
}