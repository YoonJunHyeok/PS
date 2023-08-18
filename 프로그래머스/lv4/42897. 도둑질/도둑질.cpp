#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int len = money.size();
    
    if(len == 1) {
        answer = money[0];
    }
    else if(len == 2) {
        answer = max(money[0], money[1]);
    }
    else{
        vector<int> dp1(len, 0);
        vector<int> dp2(len, 0);
        dp1[0] = money[0];
        // 0번째 집 무조건 포함.
        for(int i = 1; i < len - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
        }
        // 0번째 집 무조건 포함 안함.
        for(int i = 1; i < len; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
        }

        answer = max(dp1[len - 2], dp2[len - 1]);   
    }
    
    return answer;
}
// 어렵넹..