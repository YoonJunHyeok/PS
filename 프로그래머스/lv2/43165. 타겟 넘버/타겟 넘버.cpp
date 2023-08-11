#include <bits/stdc++.h>

using namespace std;

vector<int> cnumbers;
int ctarget, MAX, answer = 0;

void dfs(int cur, int idx) {
    if(idx == MAX) {
        if(cur == ctarget) answer++;
        return;
    }
    
    dfs(cur + cnumbers[idx], idx + 1);
    dfs(cur - cnumbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {   
    MAX = numbers.size();
    ctarget = target;
    cnumbers = vector<int> (numbers.begin(), numbers.end());
    dfs(0, 0);    
    return answer;
}