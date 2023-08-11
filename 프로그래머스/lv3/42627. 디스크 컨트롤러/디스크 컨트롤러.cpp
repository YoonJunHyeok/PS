#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if(lhs.second == rhs.second) return lhs.first < rhs.first;
    else return lhs.second < rhs.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(auto job: jobs){
        pq.push({job[1], job[0]});
    }
    
    int cur_time = 0;
    while(!pq.empty()) {
        vector<pair<int, int>> tmp;
        
        while(1) {
            int required_time, income_time;
            tie(required_time, income_time) = pq.top(); pq.pop(); 
            if(income_time > cur_time) {
                tmp.push_back({required_time, income_time});
            }
            else {
                cur_time += required_time;
                answer += (cur_time - income_time);
                for(pair<int, int> p: tmp) {
                    pq.push(p);
                }
                break;
            }
            
            if(pq.empty()) { // 현재 실행할 수 있는 job이 없다. -> 먼저 요청이 들어온 job 처리
                sort(tmp.begin(), tmp.end(), cmp);
                tie(required_time, income_time) = tmp[0];
                cur_time = income_time + required_time;
                answer += (cur_time - income_time);
                for(int i = 1; i < tmp.size(); i++) {
                    pq.push(tmp[i]);
                }
                break;
            }
        }        
    }
    
    answer /= jobs.size();
    
    return answer;
}