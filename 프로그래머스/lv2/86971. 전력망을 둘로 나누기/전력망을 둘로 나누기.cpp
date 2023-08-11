#include <bits/stdc++.h>

using namespace std;

int board[101][101] = { 0 };
int cboard[101][101];
vector<bool> visited;

int dfs(int cur, int N) {
    if(visited[cur]) return 0;
    visited[cur] = true;
    int ans = 1;
    for(int i = 1; i <= N; i++) {
        if(cboard[cur][i] && !visited[i]) {
            ans += dfs(i, N);
        }
    }
    return ans;
}

void cpy(int n) {
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            cboard[i][j] = board[i][j];
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    // init
    for(vector<int> wire: wires) {
        board[wire[0]][wire[1]] = 1;
        board[wire[1]][wire[0]] = 1;
    }
    
    for(int i = 0; i < n - 1; i++){
        cpy(n);
        visited = vector<bool> (n + 1, false);
        cboard[wires[i][0]][wires[i][1]] = 0;
        cboard[wires[i][1]][wires[i][0]] = 0;
        
        int cnt = dfs(1, n);
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}