#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<set<string>> s;
vector<string> cu, cb;
vector<bool> is_used;
int userNum, banNum;

void dfs(int idx) {
    if(idx == banNum) {
        set<string> tmp;
        for(int i = 0; i < userNum; i++) {
            if(is_used[i]) {
                tmp.insert(cu[i]);
            }
        }
        s.insert(tmp);
        return;
    }
    
    for(int i = 0; i < userNum; i++) {
        if(is_used[i]) continue;
        if(cu[i].length() != cb[idx].length()) continue;
        
        bool flag = true;
        for(int j = 0; j < cu[i].length(); j++) {
            if(cb[idx][j] != '*' && cu[i][j] != cb[idx][j]) {
                flag = false;
                break;
            }
        }
        
        if(!flag) continue;
        
        is_used[i] = true;
        dfs(idx + 1);
        is_used[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    cu = user_id;
    cb = banned_id;
    is_used = vector<bool> (user_id.size(), false);
    userNum = user_id.size();
    banNum = banned_id.size();
    
    dfs(0);
    
    return s.size();
}