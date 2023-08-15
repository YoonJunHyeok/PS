#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int left = 1, right = distance;
    while(left <= right) {
        int middle = (left + right) / 2;
        
        int cnt = 0, prevIdx = 0;
        for(int rock: rocks) {
            if(rock - prevIdx >= middle) {
                prevIdx = rock;
            }
            else{
                cnt++;
            }
        }
        
        if(distance - prevIdx < middle) cnt++;
        
        if(cnt <= n) {
            answer = middle;
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }       
    }
    
    return answer;
}