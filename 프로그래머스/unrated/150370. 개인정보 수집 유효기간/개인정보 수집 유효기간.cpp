#include <bits/stdc++.h>

using namespace std;

map<char, int> m;
char separator = '.';

vector<int> getDate(string date) { // year / month / day
    vector<string> tmp;
    vector<int> result;
    istringstream iss(date);
    string str_buf;
    while (getline(iss, str_buf, separator)) {
        tmp.push_back(str_buf);
    }
    
    for(int i = 0; i < tmp.size(); i++) {
        result.push_back(stoi(tmp[i]));
    }
    
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 1. init
    for(string str : terms) {
        char term = str[0];
        int months = stoi(str.substr(str.find(" ") + 1, str.length()));
        m[term] = months;
    }
    vector<int> cur_date = getDate(today);
    int curDateByDay = cur_date[0] * 12 * 28 + cur_date[1] * 28 + cur_date[2];
    
    // 2. count
    for(int i = 0; i < privacies.size(); i++) {
        string str = privacies[i];
        string date_str = str.substr(0, str.find(" "));
        char term = str[str.size() - 1];
        
        vector<int> term_date = getDate(date_str);  
        int termDateByDay = term_date[0] * 12 * 28 + term_date[1] * 28 + term_date[2] + m[term] * 28;
        
        if(curDateByDay >= termDateByDay) answer.push_back(i + 1);
    }
    
    return answer;
}