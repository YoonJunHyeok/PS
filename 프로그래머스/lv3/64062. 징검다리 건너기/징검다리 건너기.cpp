#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_possible(int n, int k, vector<int> &stones) {
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] - n < 0) {
            cnt++;
        }
        else{
            cnt = 0;
        }
        
        if(cnt >= k) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int len = stones.size();
    
    int left = 1, right = *max_element(stones.begin(), stones.end());
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(is_possible(mid, k, stones)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}