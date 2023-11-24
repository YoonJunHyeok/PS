#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cStones;
int jump;

bool is_possible(int num) {
    int tmpJump = 0;
    for(int i = 0; i < cStones.size(); i++) {
        if(cStones[i] < num) {
            tmpJump++;
            if(tmpJump >= jump) return false;
        }
        else {
            tmpJump = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    cStones = stones;
    jump = k;
    
    int left = 1, right = *max_element(stones.begin(), stones.end());
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(is_possible(mid)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return answer;
}