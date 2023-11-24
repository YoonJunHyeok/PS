#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<string>> s;
vector<bool> is_used;
vector<string> cUser, cBanned;
int total_user, total_ban;

bool match(string l, string r) {
    if(l.length() != r.length()) return false;
    
    for(int i = 0; i < l.length(); i++) {
        if(l[i] == r[i]) continue;
        else if(r[i] == '*') continue;
        return false;
    }
    return true;
}

void dfs(int banned_idx) {
    if(banned_idx == total_ban) {
        set<string> tmp;
        for(int i = 0; i < total_user; i++) {
            if(is_used[i]) tmp.insert(cUser[i]);
        }
        s.insert(tmp);
        return;
    }
    
    for(int idx = 0; idx < total_user; idx++) {
        if(is_used[idx]) continue;
        if(!match(cUser[idx], cBanned[banned_idx])) continue;
        is_used[idx] = true;
        dfs(banned_idx + 1);
        is_used[idx] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    is_used = vector<bool>(user_id.size(), false);
    cUser = user_id; 
    cBanned = banned_id;
    total_user = user_id.size();
    total_ban = banned_id.size();
    
    dfs(0);
    
    return s.size();
}