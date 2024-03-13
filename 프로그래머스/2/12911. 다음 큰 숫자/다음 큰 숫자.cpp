#include <string>
#include <vector>

using namespace std;

int originCnt;

bool check(int num) {
    int tmpCnt = 0;
    
    while(num > 0) {
        if(num % 2 == 1) tmpCnt++;
        num /= 2;
    }
    
    return originCnt == tmpCnt;
}

int solution(int n) {
    int answer = n + 1;
    
    while(n > 0) {
        if(n % 2 == 1) originCnt++;
        n /= 2;
    }
    
    while(1) {
        if(check(answer)) break;
        else answer++;
    }
    
    return answer;
}