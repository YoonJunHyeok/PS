#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    int s = citations.size();
    for(int i = s; i >= 1; i--) {
        if(citations[s - i] >= i) {
            answer = i;
            break;
        }
    }
    
    return answer;
}