#include <string>
#include <map>
#include <math.h>
#include <cctype>
#include <algorithm>
#define MUL 65536

using namespace std;

map<string, int> m1, m2;

int find_union_num() {
    int res = 0;
    for(auto it = m1.begin(); it != m1.end(); it++) {
        if(m2.find(it->first) == m2.end()) res += it->second;
        else res += max(it->second, m2[it->first]);
    }
    for(auto it = m2.begin(); it != m2.end(); it++) {
        if(m1.find(it->first) != m1.end()) continue;
        res += it->second;
    }
    return res;
}

int find_intersect_num() {
    int res = 0;
    for(auto it = m1.begin(); it != m1.end(); it++) {
        if(m2.find(it->first) == m2.end()) continue;
        res += min(it->second, m2[it->first]);
    }
    return res;
}

int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i = 0; i < str1.length() - 1; i++) {
        if(!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        string tmp = str1.substr(i, 2);
        m1[tmp]++;
    }
    for(int i = 0; i < str2.length() - 1; i++) {
        if(!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        string tmp = str2.substr(i, 2);
        m2[tmp]++;
    }
    
    if(m1.empty() && m2.empty()) return MUL;
    
    int union_num = find_union_num();
    int intersect_num = find_intersect_num();
    
    double jaccard = (double)intersect_num / (double)union_num;
    int answer = floor(jaccard * MUL);
    
    return answer;
}