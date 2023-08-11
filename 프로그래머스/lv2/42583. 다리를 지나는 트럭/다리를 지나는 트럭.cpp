#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, idx = 0, sum = 0;
    queue<int> q;
    
    while(1) {
        answer++;
        int tmp_weight = truck_weights[idx];
        
        if(q.size() == bridge_length) {
            sum -= q.front();
            q.pop();
        }
        
        if(sum + tmp_weight <= weight) {
            sum += tmp_weight;
            q.push(tmp_weight);
            idx++;
            if(idx >= truck_weights.size()) {
                answer += bridge_length;
                break;
            }
        }
        else{
            q.push(0);
        }
    }
    
    return answer;
}