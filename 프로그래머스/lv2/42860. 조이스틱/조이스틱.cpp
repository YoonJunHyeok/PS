#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int moveCnt = len - 1;
    
    for(int i = 0; i < len; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int idx = i + 1;
        while(idx < len && name[idx] == 'A') idx++;
        
        moveCnt = min(moveCnt, i + len - idx + min(i, len - idx));
    }
    
    answer += moveCnt;
    
    return answer;
}