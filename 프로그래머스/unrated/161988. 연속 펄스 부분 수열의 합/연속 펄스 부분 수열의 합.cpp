#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = LONG_MIN;
    int len = sequence.size();
    vector<long long> dp(len, LONG_MIN);
    
    dp[0] = (long long)sequence[0];
    answer = max(answer, dp[0]);
    for(int i = 1; i < len; i++) {
        if(i % 2 == 1) {
            dp[i] = max(dp[i - 1] - (long long)sequence[i], -(long long)sequence[i]);           
        }
        else {
            dp[i] = max(dp[i - 1] + (long long)sequence[i], (long long)sequence[i]);         
        }
        answer = max(answer, dp[i]);
    }
    
    dp[0] = -(long long)sequence[0];
    answer = max(answer, dp[0]);
    for(int i = 1; i < len; i++) {
        if(i % 2 == 1) {
            dp[i] = max(dp[i - 1] + (long long)sequence[i], (long long)sequence[i]);           
        }
        else {
            dp[i] = max(dp[i - 1] - (long long)sequence[i], -(long long)sequence[i]);         
        }
        answer = max(answer, dp[i]);
    }   
    
    return answer;
}