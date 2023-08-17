#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int max_step = triangle.size();
    
    for(int step = 1; step < max_step; step++) {
        int max_idx = triangle[step].size();
        for(int idx = 0; idx < triangle[step].size(); idx++) {
            if(idx == 0) {
                triangle[step][idx] += triangle[step - 1][idx];
            }
            else if(idx == max_idx - 1) {
                triangle[step][idx] += triangle[step - 1][idx - 1];
            }
            else {
                triangle[step][idx] += max(triangle[step - 1][idx - 1], triangle[step - 1][idx]);
            }
        }
    }
    
    answer = *max_element(triangle[max_step - 1].begin(), triangle[max_step - 1].end());
    
    return answer;
}