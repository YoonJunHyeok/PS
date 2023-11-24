#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    for(string gem: gems) {
        m[gem] = 0;
    }
    
    int left = 0, right = 0, cur_gem = 1, total_gem = m.size(), min_len = gems.size() + 1;
    m[gems[right]] = 1;
    
    while(left <= right) {
        if(cur_gem == total_gem) {
            if(right - left + 1 < min_len) {
                min_len = right - left + 1;
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
            m[gems[left]]--;
            if(m[gems[left]] == 0) cur_gem--;
            left++;
        }
        else {
            right++;
            if(right >= gems.size()) break;
            if(m[gems[right]] == 0) cur_gem++;
            m[gems[right]]++;
        }
    }
    
    return answer;
}