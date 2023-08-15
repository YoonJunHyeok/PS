#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long leftIdx = 1, rightIdx = (long long)n * (long long)times[times.size() - 1];
    
    while (leftIdx <= rightIdx) {
        long long middleIdx = (leftIdx + rightIdx) / 2;
        long long availableCnt = 0;
        for(int time: times) {
            availableCnt += middleIdx / (long long)time;
        }
        
        if(availableCnt >= n) {
            answer = middleIdx;
            rightIdx = middleIdx - 1;
        }
        else leftIdx = middleIdx + 1;
    }
    
    return answer;
}