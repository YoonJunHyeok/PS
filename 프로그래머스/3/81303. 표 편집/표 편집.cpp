#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    vector<pair<int, int>> adj;
    for(int i = 0; i < n; i++) {
        adj.push_back({i - 1, i + 1});
    }
    stack<int> deleted;
    
    for(string c: cmd) {
        if(c[0] == 'U') {
            int dist = stoi(c.substr(2));
            while(dist--) {
                k = adj[k].first;
            }
        }
        else if(c[0] == 'D') {
            int dist = stoi(c.substr(2));
            while(dist--) {
                k = adj[k].second;
            }            
        }
        else if(c[0] == 'C') {
            answer[k] = 'X';
            deleted.push(k);
            int prevIdx = adj[k].first;
            int nxtIdx = adj[k].second;

            if(prevIdx != -1) adj[prevIdx].second = nxtIdx;
            if(nxtIdx != n) adj[nxtIdx].first = prevIdx;

            if(nxtIdx == n) k = prevIdx;
            else k = nxtIdx;    
        }
        else if(c[0] == 'Z') {
            if(!deleted.empty()) {
                int idx = deleted.top();
                deleted.pop();
                answer[idx] = 'O';

                int prevIdx = adj[idx].first;
                int nxtIdx = adj[idx].second;

                if(prevIdx != -1) adj[prevIdx].second = idx;
                if(nxtIdx != n) adj[nxtIdx].first = idx;
            }
        }
    }    
    
    return answer;
}