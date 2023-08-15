#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> dp(9);

int solution(int N, int number) {   
    if(N == number) return 1;
    dp[1].insert(N);
    
    for(int step = 2; step <= 8; step++) {
        int tmp = N;
        for(int i = 2; i <= step; i++) {
            tmp = tmp * 10 + N;
        }
        dp[step].insert(tmp);
        
        for(int i = 1; i < step; i++) {
            for(int a: dp[i]) {
                for(int b: dp[step - i]) {
                    dp[step].insert(a + b);
                    dp[step].insert(a * b);
                    if(a - b > 0) dp[step].insert(a - b);
                    if(a / b > 0) dp[step].insert(a / b);
                }
            }
        }
        
        if(dp[step].find(number) != dp[step].end()) {
            return step;
        }
    }
    
    return -1;
}