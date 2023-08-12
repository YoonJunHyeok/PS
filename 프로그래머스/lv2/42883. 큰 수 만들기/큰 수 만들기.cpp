#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int answerSize = number.length() - k;
    
    int curIdx = 0;
    for(int i = 0; i < answerSize; i++) {
        char maxInt = number[curIdx];
        int maxIdx = curIdx;
        for(int j = curIdx; j <= k + i; j++) {
            if(number[j] > maxInt) {
                maxInt = number[j];
                maxIdx = j;
            }
        }
        curIdx = maxIdx + 1;
        answer += maxInt;
    }
    
    return answer;
    // 어렵넹..
}