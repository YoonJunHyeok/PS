#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> m;
    for(string gem: gems) {
        m[gem] = 0;
    }
    int start = 0, end = 0;
    m[gems[end]]++;
    int total_gems = m.size(), cur_gems = 1, min_len = gems.size() + 1;
    while(true) {
        if(cur_gems == total_gems) {
            if(end - start + 1 < min_len) {
                answer[0] = start + 1;
                answer[1] = end + 1;
                min_len = end - start + 1;
            }
            
            if(m[gems[start]] == 1) {
                cur_gems--;
            }
            m[gems[start]]--;
            start++;
        }
        else if(end == gems.size() - 1) break;
        else {
            end++;
            if(m[gems[end]] == 0) {
                cur_gems++;
            }
            m[gems[end]]++;
        }
    }
    
    return answer;
}