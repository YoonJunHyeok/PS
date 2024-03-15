#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cal(int num, int n) {
    if(num == 0) {
        return vector<int>(1, 0);
    }
    
    vector<int> tmp;
    while(num > 0) {
        tmp.push_back(num % n);
        num /= n;
    }
    
    reverse(tmp.begin(), tmp.end());
    
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    vector<int> v;
    int num = 0;
    while(v.size() <= t * m) {
        vector<int> tmp = cal(num, n);
        v.insert(v.end(), tmp.begin(), tmp.end());
        num++;
    }
    
    for(int idx = 0; idx < t; idx++) {
        int cur_num = v[p + idx * m - 1];
        if(cur_num < 10) {
            answer += to_string(cur_num);
        }
        else {
            answer += 'A' + (cur_num % 10);
        }
    }
    
    return answer;
}