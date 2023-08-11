#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pqa;
    priority_queue<int, vector<int>, less<int>> pqd;
    int count = 0;
    
    for(string op: operations) {
        string order = op.substr(0, op.find(' '));
        int num = stoi(op.substr(op.find(' ') + 1, op.length()));
        
        if(count <= 0) {
            while(!pqa.empty()) pqa.pop();
            while(!pqd.empty()) pqd.pop();
        }
        
        if(order == "I") {
            pqa.push(num);
            pqd.push(num);
            count++;
        }
        else if(order == "D") {
            if(count <= 0) continue;
            
            if(num == 1) {
                pqd.pop();
                count--;
            }
            else if(num == -1) {
                pqa.pop();
                count--;
            }
        }
    }
    
    if(count > 0) {
        answer.push_back(pqd.top());
        answer.push_back(pqa.top());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}