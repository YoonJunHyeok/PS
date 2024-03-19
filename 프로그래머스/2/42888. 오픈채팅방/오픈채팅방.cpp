#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> m; // {uid, (final) nickname}
    
    string action, uuid, nickname;
    for(string s: record) {
        stringstream ss(s);
        ss >> action >> uuid >> nickname;
        
        if(action == "Enter" || action == "Change") {
            m[uuid] = nickname;
        }
    }
    
    for(string s: record) {
        stringstream ss(s);
        ss >> action >> uuid >> nickname;
        
        string str = m[uuid];
        
        if(action == "Enter") {
            str += "님이 들어왔습니다.";
        }
        else if(action == "Leave") {
            str += "님이 나갔습니다.";
        }
        else {
            continue;
        }
        
        answer.push_back(str);
    }
    
    return answer;
}