#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> lhs, vector<int> rhs) {
    return lhs[1] < rhs[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int totalTargets = targets.size();
    
    sort(targets.begin(), targets.end(), cmp);
    
    int idx = 1;
    int prevEnd = targets[0][1];
    while(1) {
        if(idx >= totalTargets) break;
        
        if(targets[idx][0] >= prevEnd) {
            answer++;
            prevEnd = targets[idx][1];
        }
        
        idx++;
    }
    
    answer++;
    
    return answer;
}