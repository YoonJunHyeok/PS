#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999;
int answer = INF;
vector<bool> visited;

bool check(string lhs, string rhs) {
    int cnt = 0;
    for(int i = 0; i < lhs.length(); i++) {
        if(lhs[i] != rhs[i]) cnt++;
    }
    
    if(cnt == 1) return true;
    else return false;
}

void dfs(string cur, string target, vector<string> &words, int step) {
    if(answer <= step) return;
    if(cur == target) {
        answer = min(answer, step);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        if(check(cur, words[i]) && !visited[i]) {
            visited[i] = true;
            dfs(words[i], target, words, step + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {    
    visited = vector<bool> (words.size(), false);
    dfs(begin, target, words, 0);    
    if(answer == INF) answer = 0;
    return answer;
}