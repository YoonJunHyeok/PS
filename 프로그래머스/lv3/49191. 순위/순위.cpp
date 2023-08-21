#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    
    for(vector<int> result: results) {
        board[result[0]][result[1]] = 1;
        board[result[1]][result[0]] = -1;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j] == 0) {
                    if(board[i][k] == 1 && board[k][j] == 1) {
                        board[i][j] = 1;
                    }
                    else if(board[i][k] == -1 && board[k][j] == -1) {
                        board[i][j] = -1;
                    }
                }
                
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(board[i][j] != 0) cnt++;
        }
        if(cnt == n - 1) answer++;
    }
    
    return answer;
}