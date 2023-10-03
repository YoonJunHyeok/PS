#include <vector>
#include <iostream> 

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int dp[500][500][2] = { 0 };
    // 0은 아래쪽으로, 1은 오른쪽으로
    
    dp[0][0][0] = 1;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int prevX = i - 1, prevY = j;
            if(prevX >= 0 && prevY >= 0) {
                if(city_map[prevX][prevY] == 0) {
                    dp[i][j][0] = (dp[prevX][prevY][0] + dp[prevX][prevY][1]) % MOD;
                }
                else if(city_map[prevX][prevY] == 2) {
                    dp[i][j][0] = dp[prevX][prevY][0];
                }
            }
            
            prevX = i, prevY = j - 1;
            if(prevX >= 0 && prevY >= 0) {
                if(city_map[prevX][prevY] == 0) {
                    dp[i][j][1] = (dp[prevX][prevY][0] + dp[prevX][prevY][1]) % MOD;
                }
                else if(city_map[prevX][prevY] == 2) {
                    dp[i][j][1] = dp[prevX][prevY][1];
                }
            }
        }
    }
    
    answer = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    return answer;
}