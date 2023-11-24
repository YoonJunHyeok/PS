#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, int> m; // key: 숫자, value: 우선순위

vector<int> solution(string s) {
    vector<int> answer;
    
    string tmpNum = "";
    vector<int> tmpGroup;
    for(int i = 1; i < s.length() - 1; i++) {
        if(s[i] == '{') {
            tmpGroup.clear();
        }
        else if(s[i] == '}') {
            tmpGroup.push_back(stoi(tmpNum));
            tmpNum = "";
            
            int priority = tmpGroup.size();
            for(int num: tmpGroup) {
                if(m.find(num) == m.end()) {
                    m[num] = priority;
                }
                else {
                    m[num] = min(m[num], priority);
                }
            }
        }
        else if(s[i] == ',') {
            if(tmpNum != "") tmpGroup.push_back(stoi(tmpNum));
            tmpNum = "";
        }
        else { // 숫자
            tmpNum += s[i];
        }
    }
    
    answer = vector<int>(m.size());
    
    for(auto it = m.begin(); it != m.end(); it++) {
        answer[it->second - 1] = it->first;
    }
    
    return answer;
}