#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board.size();
    stack<int> s;
    
    for(int move: moves) {
        int doll = 0;
        for(int idx = 0; idx < N; idx++) {
            if(board[idx][move - 1] != 0) {
                doll = board[idx][move - 1];
                board[idx][move - 1] = 0;
                break;
            }
        }
        
        if(!doll) continue;
        
        if(!s.empty()) {
            int top_doll = s.top();
            if(top_doll == doll) {
                s.pop();
                answer += 2;
            }
            else {
                s.push(doll);
            }
        }
        else {
            s.push(doll);
        }
    }
    
    
    return answer;
}