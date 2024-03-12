#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<int> cnt(2410, 0);
    for(vector<string> tm: book_time) {
        int start_time = stoi(tm[0].substr(0, 2) + tm[0].substr(3, 5));
        int end_time = stoi(tm[1].substr(0, 2) + tm[1].substr(3, 5));
        if(end_time % 100 < 50) end_time += 10;
        else end_time = end_time + 100 - 50;
        // 00:59 + 10 = 01:09 != 00:69
        
        for(int idx = start_time; idx < end_time; idx++) {
            cnt[idx]++;
        }
    }
    
    answer = *max_element(cnt.begin(), cnt.end());
    
    return answer;
}
