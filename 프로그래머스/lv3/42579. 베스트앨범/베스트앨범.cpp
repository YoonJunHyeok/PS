#include <bits/stdc++.h>

using namespace std;

static bool cmp1(pair<string, vector<pair<int, int>>>&lhs, pair<string, vector<pair<int, int>>>&rhs) {
    vector<pair<int, int>> lhsv = lhs.second;
    vector<pair<int, int>> rhsv = rhs.second;    
    int lhsSum = 0;
    for(int i = 0; i < lhsv.size(); i++) {
        lhsSum += lhsv[i].second;
    }
    int rhsSum = 0;
    for(int i = 0; i < rhsv.size(); i++) {
        rhsSum += rhsv[i].second;
    }   
    
    return lhsSum > rhsSum;
} 

static bool cmp2(pair<int, int>&lhs, pair<int, int>&rhs) {
    if(lhs.second == rhs.second) {
        return lhs.first < rhs.first;
    }
    return lhs.second > rhs.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> m;
    for(int i = 0; i < genres.size(); i++) {
        if(m.find(genres[i]) == m.end()) {
            vector<pair<int, int>> v;
            v.push_back({i, plays[i]});
            m[genres[i]] = v;
        }
        else{
            vector<pair<int, int>> v = m[genres[i]];
            v.push_back({i, plays[i]});
            m[genres[i]] = v;
        }
    }
    vector<pair<string, vector<pair<int, int>>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp1);
    
    for(int i = 0; i < v.size(); i++) {
        vector<pair<int, int>> tmp = v[i].second;
        cout << v[i].first << endl;
        sort(tmp.begin(), tmp.end(), cmp2);
        if(tmp.size() >= 2) {
            answer.push_back(tmp[0].first);
            answer.push_back(tmp[1].first);
        }
        else{
            answer.push_back(tmp[0].first);
        }
    }
    
    
    return answer;
}