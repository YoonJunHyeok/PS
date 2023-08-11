#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> candidate;
vector<bool> used;

bool cmp(vector<string> &lhs, vector<string> &rhs) {
    for(int i = 0; i < lhs.size(); i++) {
        if(lhs[i] == rhs[i]) continue;
        return lhs[i] < rhs[i];
    }
}

void dfs(vector<vector<string>> &tickets, string cur, deque<string> dq, int step) {
    if(step == used.size()) {
        vector<string> tmp;
        for(int i = 0; i < dq.size(); i++) {
            tmp.push_back(dq[i]);
        }
        candidate.push_back(tmp);
    }
    
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] != cur || used[i]) continue;
        used[i] = true;
        dq.push_back(tickets[i][1]);
        dfs(tickets, tickets[i][1], dq, step + 1);
        used[i] = false;
        dq.pop_back();
    }    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    used = vector<bool> (tickets.size(), false);
    
    deque<string> tmp;
    tmp.push_back("ICN");
    dfs(tickets, "ICN", tmp, 0);
    
    sort(candidate.begin(), candidate.end(), cmp);
    
    answer = candidate[0];
    
    return answer;
}