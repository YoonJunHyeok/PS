#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um[11]; // um[i]는 길이가 i인 string만 존재

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    vector<string> ordered_orders;
    for(string order: orders) {
        vector<char> tmp;
        for(char c: order) {
            tmp.push_back(c);
        }
        
        sort(tmp.begin(), tmp.end());
        
        string s = "";
        for(char c: tmp) {
            s += c;
        }
        
        ordered_orders.push_back(s);
    }
    
    for(string order: ordered_orders) {
        int len = order.length();
        
        for(int i = 2; i <= len; i++) {
            vector<int> v;
            for(int j = 0; j < len - i; j++) v.push_back(0);
            for(int j = 0; j < i; j++) v.push_back(1);
            
            do {
                string tmp = "";
                for(int j = 0; j < len; j++) {
                    if(v[j]) tmp += order[j];
                }
                
                um[i][tmp]++;
            } while(next_permutation(v.begin(), v.end()));
        }
    }
    
    for(int n: course) {
        int max_order = 2;
        vector<string> tmp;
        
        for(auto iter: um[n]) {
            if(iter.second > max_order) {
                max_order = iter.second;
                tmp.clear();
                tmp.push_back(iter.first);
            }
            else if(iter.second == max_order) {
                tmp.push_back(iter.first);
            }
        }
        
        for(string s: tmp) {
            answer.push_back(s);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}