#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<pair<int, int>>> board(n + 1, vector<pair<int, int>> (n + 1, {-1, -1}));
    // {기둥, 보} = {0, 1}
    for(vector<int> cmd: build_frame) {
        int x = cmd[0], y = cmd[1], a = cmd[2], b = cmd[3];
        if (a == 0) { // 기둥
            if (b == 0) { // 삭제
                bool flag = true;
                
                if(y + 1 <= n && board[x][y + 1].first == 0) { // 위에 기둥 있을 때
                    if((x - 1 >= 0 && board[x - 1][y + 1].second == 1) || board[x][y + 1].second == 1) {
                        flag = flag;
                    }
                    else {
                        flag = false;
                    }
                }
                
                if(x - 1 >= 0 && y + 1 <= n && board[x - 1][y + 1].second == 1) { // 왼쪽 위에 보 있을 때
                    if(board[x - 1][y].first == 0 || (x - 2 >= 0 && board[x - 2][y + 1].second == 1 && board[x][y + 1].second == 1)) {
                        flag = flag;
                    }
                    else {
                        flag = false;
                    }
                }
                
                if(y + 1 <= n && board[x][y + 1].second == 1) { // 위에 보 있을 때
                    if((x + 1 <= n && board[x + 1][y].first == 0) || (x - 1 >= 0 && x + 1 <= n && board[x - 1][y + 1].second == 1 && board[x + 1][y + 1].second == 1)) {
                        flag = flag;
                    }
                    else {
                        flag = false;
                    }
                }
                
                if(flag) {
                    board[x][y].first = -1;
                }
            }
            else if(b == 1) { // 설치
                if (y == 0 
                    || (x - 1 >= 0 && board[x - 1][y].second == 1) 
                    || board[x][y].second == 1
                    || (y - 1 >= 0 && board[x][y - 1].first == 0)) 
                {
                    board[x][y].first = 0;
                }
            }
        }
        else if(a == 1) { // 보
            if (b == 0) { // 삭제
                bool flag = true;
                
                if(board[x][y].first == 0) { // 왼쪽에 기둥 있을 때
                    if((y - 1 >= 0 && board[x][y - 1].first == 0) || (x - 1 >= 0 && board[x - 1][y].second == 1)) {
                        flag = flag;
                    }
                    else{
                        flag = false;
                    }
                }
                
                if(x + 1 <= n && board[x + 1][y].first == 0) { // 오른쪽에 기둥 있을 때
                    if((y - 1 >= 0 && board[x + 1][y - 1].first == 0) || board[x + 1][y].second == 1) {
                        flag = flag;
                    }
                    else {
                        flag = false;
                    }
                }
                
                if(x - 1 >= 0 && board[x - 1][y].second == 1) { // 왼쪽으로 보 있을 때
                    if(y - 1 >= 0 && (board[x - 1][y - 1].first == 0 || board[x][y - 1].first == 0)) {
                        flag = flag;
                    }
                    else {
                        flag = false;
                    }
                }
                
                if(x + 1 <= n && board[x + 1][y].second == 1) { // 오른쪽으로 보 있을 때
                    if(y - 1 >= 0 && (board[x + 1][y - 1].first == 0 || (x + 2 <= n && board[x + 2][y - 1].first == 0))) {
                        flag = flag;
                    }
                    else {
                        flag = false;
                    }
                }
                
                if(flag) {
                    board[x][y].second = -1;
                }
            }
            else if(b == 1) { // 설치
                if((y - 1 >= 0 && board[x][y - 1].first == 0) 
                   || (x + 1 <= n && y - 1 >= 0 && board[x + 1][y - 1].first == 0 )
                   || (x - 1 >= 0 && x + 1 <= n && board[x - 1][y].second == 1 && board[x + 1][y].second == 1)) 
                {
                    board[x][y].second = 1;
                }
            }
        }
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(board[i][j].first == 0) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(board[i][j].first);
                answer.push_back(tmp);
            }
            if(board[i][j].second == 1) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(board[i][j].second);
                answer.push_back(tmp);
            }
        }
    }
    
    return answer;
}