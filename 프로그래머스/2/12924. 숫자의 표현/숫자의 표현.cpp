#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int start = 1, end = 1, cur = 1;
    
    while(end <= n && start <= end) {
        if(cur == n) {
            answer++;
        }
        
        if(cur < n) {
            end++;
            cur += end;
        }
        else {
            cur -= start;
            start++;
        }
    }
    
    return answer;
}