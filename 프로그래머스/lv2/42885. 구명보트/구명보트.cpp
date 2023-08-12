#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq(people.begin(), people.end());
    sort(dq.begin(), dq.end());
    
    while(dq.size() >= 2) {
        if(dq.front() + dq.back() <= limit) {
            dq.pop_front();
            dq.pop_back();
            answer++;
        } 
        else {
            dq.pop_back();
            answer++;
        }
    }
    if(!dq.empty()) answer++;
    
    return answer;
}