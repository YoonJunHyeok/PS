#include <bits/stdc++.h>

using namespace std;

bool cmp (string a, string b) {
    string x = a + b;
    string y = b + a;
    if(stoi(x) > stoi(y)) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strings;
    for(auto number : numbers) {
        strings.push_back(to_string(number));
    }
    
    sort(strings.begin(), strings.end(), cmp);
    if(strings[0][0] == '0') {
        answer = "0";
    }
    else{ 
        for(auto str : strings) {
            answer += str;
        }   
    }
    
    return answer;
}