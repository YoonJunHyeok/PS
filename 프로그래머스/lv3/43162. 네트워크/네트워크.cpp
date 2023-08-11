#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
int num;

void dfs(vector<vector<int>> &board, int cur) {
    visited[cur] = true;
    for(int i = 0; i < num; i++) {
        if(board[cur][i] && !visited[i]) {
            dfs(board, i);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    num = n;
    visited = vector<bool> (n, false);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            dfs(computers, i);
        }
    }
    
    return answer;
}