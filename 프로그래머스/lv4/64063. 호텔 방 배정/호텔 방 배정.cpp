#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> m;
    
    for(long long r: room_number) {
        if(m.find(r) == m.end()) {
            m[r] = r + 1;
            answer.push_back(r);
        }
        else {
            vector<long long> tmp;
            tmp.push_back(r);
            long long idx = m[r];
            
            while(1) {
                if(m.find(idx) == m.end()) {
                    m[idx] = idx + 1;
                    answer.push_back(idx);
                    for(long long tmpIdx: tmp) {
                        m[tmpIdx] = idx + 1;
                    }
                    
                    break;
                }
                else {
                    tmp.push_back(idx);
                    idx = m[idx];
                }
            }
        }
    }
    
    return answer;
}