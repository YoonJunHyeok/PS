#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
    }
    
    queue<int> q;
    for(int i = 0; i < priorities.size(); i++) q.push(i);
    
    int idx = 0;
    while(!q.empty()) {
        int cur_location = q.front(); q.pop();
        if(priorities[cur_location] < pq.top()) {
            q.push(cur_location);
        }
        else{
            idx++;
            pq.pop();
            if(cur_location == location){
                answer = idx;
                break;
            }
        }
    }
    
    return answer;
}