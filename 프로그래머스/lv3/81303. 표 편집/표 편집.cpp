#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    stack<int> trashCan;
    vector<pair<int, int>> llist;
    for(int i = 0; i < n; i++) {
        llist.push_back({i - 1 ,i + 1});
    }
    
    int curIdx = k;
    for(string curCmd: cmd) {
        if(curCmd[0] == 'U') {
            int dist = stoi(curCmd.substr(2));
            while(dist > 0) {
                curIdx = llist[curIdx].first;
                dist--;
            }
        }
        else if(curCmd[0] == 'D') {
            int dist = stoi(curCmd.substr(2));
            while(dist > 0) {
                curIdx = llist[curIdx].second;
                dist--;
            }
        }
        else if(curCmd[0] == 'C') {
            trashCan.push(curIdx);
            answer[curIdx] = 'X';
            
            int prev = llist[curIdx].first;
            int nxt = llist[curIdx].second;
            
            if (prev != -1) llist[prev].second = nxt;
            if(nxt != n) llist[nxt].first = prev;
            
            if (nxt == n) curIdx = prev;
            else curIdx = nxt;
        }
        else if(curCmd[0] == 'Z') {
            int reIdx = trashCan.top();
            trashCan.pop();
            answer[reIdx] = 'O';
            
            int prev = llist[reIdx].first;
            int nxt = llist[reIdx].second;
            
            if(prev != -1) llist[prev].second = reIdx;
            if(nxt != n) llist[nxt].first = reIdx;
        }
    }
    
    return answer;
}