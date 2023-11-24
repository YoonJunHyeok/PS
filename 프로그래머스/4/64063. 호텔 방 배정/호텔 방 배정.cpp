#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> m;

long long find(long long idx) {
    if(m.find(idx) == m.end()) {
        m[idx] = idx + 1;
        return idx;
    }
    else {
        long long nxtIdx = find(m[idx]);
        m[idx] = nxtIdx + 1;
        return nxtIdx;
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(long long rn: room_number) {
        long long idx = find(rn);
        answer.push_back(idx);
    }
    
    return answer;
}