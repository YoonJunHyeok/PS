#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    for(int idx = 0; idx < 26; idx++) {
        string tmp = "";
        tmp += 'A' + idx;
        m.insert({tmp, idx + 1});
    }
    
    int len = msg.length();
    string str = msg.substr(0, 1);
    
    for(int idx = 1; idx < len; idx++) {
        if(m.find(str + msg[idx]) != m.end()) {
            str += msg[idx];
        }     
        else {
            answer.push_back(m[str]);
            m.insert({str + msg[idx], m.size() + 1});
            str = msg.substr(idx, 1);
        }
    }
    answer.push_back(m[str]);    
    
    return answer;
}