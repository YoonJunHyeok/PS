#include <string>
#include <vector>
#define DIVIDE 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n + 1, 0);
    
    dp[0] = 1;
    for(int m: money) {
        for(int i = m; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - m]) % DIVIDE;
        }
    }
    
    answer = dp[n];
    
    return answer;
}
// 흠..