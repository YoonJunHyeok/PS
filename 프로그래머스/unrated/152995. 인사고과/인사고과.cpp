#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> lhs, vector<int> rhs) {
    return lhs[0] + lhs[1] > rhs[0] + rhs[1];
}

int solution(vector<vector<int>> scores) {
    int len = scores.size();
    for(int idx = 0; idx < len; idx++) {
        scores[idx].push_back(idx);
    }
    sort(scores.begin(), scores.end(), cmp);
    
    if(scores[0][2] == 0) return 1;
    
    int rank = 1, sameRank = 0;
    int prevSum = scores[0][0] + scores[0][1];
    
    for(int idx = 1; idx < len; idx++) {
        bool flag = true;
        for(int prev = 0; prev < idx; prev++) {
            if(scores[idx][0] < scores[prev][0] && scores[idx][1] < scores[prev][1]) {
                flag = false;
                break;
            }
        }
        
        if(flag) {            
            int curSum = scores[idx][0] + scores[idx][1];
            if(prevSum == curSum) {
                sameRank++;
            }
            else {
                rank = rank + sameRank + 1;
                prevSum = curSum;
                sameRank = 0;
            }
            
            if(scores[idx][2] == 0) return rank;
        }
        else{
            if(scores[idx][2] == 0) return -1;
        }
    }
}