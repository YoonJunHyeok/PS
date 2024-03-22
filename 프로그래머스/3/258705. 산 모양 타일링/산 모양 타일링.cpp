#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    vector<vector<int>> dp(n, vector<int> (2, 0)); // 역삼각형 기준으로 오른쪽 아래 삼각형 사용 유/무
    dp[0][0] = 1;
    dp[0][1] = tops[0] == 0 ? 2 : 3;
    
    for(int idx = 1; idx < n; idx++) {
        if(tops[idx]) {
            dp[idx][0] = (dp[idx - 1][0] + dp[idx - 1][1]) % 10007;
            dp[idx][1] = (2 * dp[idx - 1][0] + 3 * dp[idx - 1][1]) % 10007;
        }
        else {
            dp[idx][0] = (dp[idx - 1][0] + dp[idx - 1][1]) % 10007;
            dp[idx][1] = (dp[idx - 1][0] + 2 * dp[idx - 1][1]) % 10007;
        }
    }
    
    answer = (dp[n - 1][0] + dp[n - 1][1]) % 10007;
    
    return answer;
}