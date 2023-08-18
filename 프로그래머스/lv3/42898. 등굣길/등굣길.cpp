#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;
    for(vector<int> puddle: puddles) {
        dp[puddle[1]][puddle[0]] = -1;
    }
    
    for(int dx = 1; dx <= n; dx++) {
        for(int dy = 1; dy <= m; dy++) {
            if(dp[dx][dy] == -1) continue;
            
            int leftx = dx, lefty = dy - 1;
            if(lefty >= 1 && dp[leftx][lefty] != -1) 
                dp[dx][dy] = (dp[dx][dy] + dp[leftx][lefty]) % MAX;
            
            int upperx = dx - 1, uppery = dy;
            if(upperx >= 1 && dp[upperx][uppery] != -1) 
                dp[dx][dy] = (dp[dx][dy] + dp[upperx][uppery]) % MAX;
        }
    }    
    
    answer = dp[n][m];
    
    return answer;
}