#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int cnt[360000];

int get_sec(string strTime) {
    int returnSec = 0;
    returnSec += stoi(strTime.substr(0, 2)) * 60 * 60;
    returnSec += stoi(strTime.substr(3, 2)) * 60;
    returnSec += stoi(strTime.substr(6, 2));
    
    return returnSec;
}

string get_str(int intTime) {
    string returnStr = "";
    
    int time = (intTime / 60) / 60;
    int minute = (intTime / 60) % 60;
    int second = intTime % 60;
    returnStr += char('0' + (time / 10));
    returnStr += char('0' + (time % 10));
    returnStr += ':';
    returnStr += char('0' + (minute / 10));
    returnStr += char('0' + (minute % 10));
    returnStr += ':';
    returnStr += char('0' + (second / 10));
    returnStr += char('0' + (second % 10));
    
    return returnStr;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTime = get_sec(play_time), advTime = get_sec(adv_time);
    for(string log: logs) {
        int startTime = get_sec(log.substr(0, 8));
        int endTime = get_sec(log.substr(9, 8));
        for(int idx = startTime; idx < endTime; idx++) {
            cnt[idx]++;
        }
    }
    
    long long cur = 0;
    long long MAX = 0;
    queue<int> q;
    
    for(int idx = 0; idx < advTime; idx++) {
        cur += cnt[idx];
        q.push(cnt[idx]);
    }
    MAX = cur;
    answer = get_str(0);
    
    for(int idx = advTime; idx < playTime; idx++) {
        cur -= q.front();
        q.pop();
        cur += cnt[idx];
        q.push(cnt[idx]);
        if(MAX < cur) {
            MAX = cur;
            answer = get_str(idx - advTime + 1);
        }
    }                              
    
    return answer;
}