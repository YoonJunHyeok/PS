#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    answer = dp[n];
    return answer;
}