#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool flag = false;
    
    do {
        vector<vector<bool>> used(m, vector<bool>(n, false));
        flag = false;
        
        // 2 x 2 확인
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(board[i][j] == 'X') continue;
                if(board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
                    used[i][j] = true;
                    used[i][j + 1] = true;
                    used[i + 1][j] = true;
                    used[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }
        
        // 점수 계산 및 board에 반영
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(used[i][j]) {
                    board[i][j] = 'X';
                    answer++;
                }
            }
        }
        
        // 아래로 내리기
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    for(int k = i - 1; k >= 0; k--) {
                        if(board[k][j] == 'X') break;
                        
                        board[k + 1][j] = board[k][j];
                        board[k][j] = 'X';
                    }
                }
            }
        }     
    } while(flag);
    
    return answer;
}