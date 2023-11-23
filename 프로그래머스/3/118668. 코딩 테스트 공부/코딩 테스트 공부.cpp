#include <string>
#include <vector>
#include <climits>
#include <algorithm>

#define alp_req 0
#define cop_req 1
#define alp_rwd 2
#define cop_rwd 3
#define cost 4

using namespace std;

int dp[152][152];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = -1, max_cop = -1;
    
    for(auto p: problems) {
        max_alp = max(max_alp, p[alp_req]);
        max_cop = max(max_cop, p[cop_req]);
    }
    for(int i = 0; i <= max_alp; i++) {
        fill(dp[i], dp[i] + max_cop + 1, INT_MAX);
    }
    
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    
    dp[alp][cop] = 0;
        
    for(int i = alp; i <= max_alp; i++) {
        for(int j = cop; j <= max_cop; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            
            for(auto p: problems) {
                if(p[alp_req] > i || p[cop_req] > j) continue;
                
                int nxtI = min(i + p[alp_rwd], max_alp);
                int nxtJ = min(j + p[cop_rwd], max_cop);
                dp[nxtI][nxtJ] = min(dp[nxtI][nxtJ], dp[i][j] + p[cost]);
            }
        }
    }
    
    return dp[max_alp][max_cop];
}