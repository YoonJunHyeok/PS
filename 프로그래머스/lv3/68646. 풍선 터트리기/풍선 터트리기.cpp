#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int minIdx, minNum = INT_MAX;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < minNum) {
            minIdx = i;
            minNum = a[i];
        }
    }
    
    int leftIdx = 0, rightIdx = a.size() - 1;
    int leftMin = INT_MAX, rightMin = INT_MAX;
    for(int idx = leftIdx; idx < minIdx; idx++) {
        if(a[idx] < leftMin) {
            leftMin = a[idx];
            answer++;
        }
    }
    
    for(int idx = rightIdx; idx > minIdx; idx--) {
        if(a[idx] < rightMin) {
            rightMin = a[idx];
            answer++;
        }
    }
    
    // for minimum of a
    answer++;   
    
    return answer;
}