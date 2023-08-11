#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    map<int, int> m;
    
    for(int num: nums) {
        m[num] = 0;
    }
    
    answer = min(m.size(), (nums.size() / 2));
    
    
    return answer;
}