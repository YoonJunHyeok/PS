#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = "";
    
    for(int idx = 0; idx < s.length(); idx++) {
        if(s[idx] >= '0' && s[idx] <= '9') {
            tmp += s[idx];
        }
        else {
            if(s.substr(idx, 4) == "zero") {
                tmp += '0';
                idx += 3;
            }
            else if(s.substr(idx, 3) == "one") {
                tmp += '1';
                idx += 2;
            }
            else if(s.substr(idx, 3) == "two") {
                tmp += '2';
                idx += 2;
            }
            else if(s.substr(idx, 5) == "three") {
                tmp += '3';
                idx += 4;
            }
            else if(s.substr(idx, 4) == "four") {
                tmp += '4';
                idx += 3;
            }
            else if(s.substr(idx, 4) == "five") {
                tmp += '5';
                idx += 3;
            }
            else if(s.substr(idx, 3) == "six") {
                tmp += '6';
                idx += 2;
            }
            else if(s.substr(idx, 5) == "seven") {
                tmp += '7';
                idx += 4;
            }
            else if(s.substr(idx, 5) == "eight") {
                tmp += '8';
                idx += 4;
            }
            else if(s.substr(idx, 4) == "nine") {
                tmp += '9';
                idx += 3;
            }
        }
    }
    
    answer = stoi(tmp);
    
    return answer;
}