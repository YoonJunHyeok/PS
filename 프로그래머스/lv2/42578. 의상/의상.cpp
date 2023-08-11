#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(auto cloth: clothes) {
        m[cloth[1]] += 1;
    }
    
    for(auto it: m) {
        answer *= (it.second + 1);
    }
    answer--;
    
    return answer;
}