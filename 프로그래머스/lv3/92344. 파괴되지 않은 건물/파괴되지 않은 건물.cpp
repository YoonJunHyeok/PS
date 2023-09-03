#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size(), M = board[0].size();
    vector<vector<int>> accum(N + 1, vector<int> (M + 1, 0));
    for(vector<int> s: skill) {
        int type=s[0], r1=s[1], c1=s[2], r2=s[3], c2=s[4], d=s[5];
        if(type == 1) {
            accum[r1][c1] -= d;
            accum[r1][c2 + 1] += d;
            accum[r2 + 1][c1] += d;
            accum[r2 + 1][c2 + 1] -= d;
        }
        else{
            accum[r1][c1] += d;
            accum[r1][c2 + 1] -= d;
            accum[r2 + 1][c1] -= d;
            accum[r2 + 1][c2 + 1] += d;
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < M; j++) {
            accum[i][j] += accum[i][j - 1];
        }
    }
    
    for(int j = 0; j < M; j++) {
        for(int i = 1; i < N; i++) {
            accum[i][j] += accum[i - 1][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] += accum[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}