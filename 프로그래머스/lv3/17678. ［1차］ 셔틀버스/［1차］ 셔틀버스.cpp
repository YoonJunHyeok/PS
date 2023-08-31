#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getMinute(string time) {
    char hour1 = time[0] - '0';
    char hour2 = time[1] - '0';
    char minute1 = time[3] - '0';
    char minute2 = time[4] - '0';
    return (hour1 * 10 * 60) + (hour2 * 60) + (minute1 * 10) + minute2;
}

string getString(int time) {
    string ans = "";
    int hour = time / 60;
    int minute = time % 60;
    ans += (hour / 10) + '0';
    ans += (hour % 10) + '0';
    ans += ':';
    ans += (minute / 10) + '0';
    ans += (minute % 10) + '0';
    
    return ans;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int len = timetable.size();
    vector<int> wait;
    for(string time: timetable) {
        wait.push_back(getMinute(time));
    }
    sort(wait.begin(), wait.end());
    
    int idx = 0;
    int tmpTime = 0;
    for(int i = 0; i < n; i++) {
        int shuttle = 9 * 60 + i * t, tmpCnt = 0, lastTime;
        
        while(1) {
            if(idx >= len || tmpCnt >= m || wait[idx] > shuttle) break;
            lastTime = wait[idx];
            idx++;
            tmpCnt++;
        }
        
        if(tmpCnt < m) {
            tmpTime = max(tmpTime, shuttle);
        }
        else{
            tmpTime = max(tmpTime, lastTime - 1);
        }
    }
    answer = getString(tmpTime);
    
    return answer;
}