#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    
    while(n > 0) {
        int top1 = pq.top(); pq.pop();
        if(top1 == 0) break;
        int top2 = pq.top(); pq.pop();
        int gap = top1 - top2;
        
        if(gap == 0) {
            top1--;
            n--;
        }
        else if(gap <= n) {
            top1 -= gap;
            n -= gap;
        }
        else if(gap > n) {
            top1 -= n;
            n = 0;
        }
        pq.push(top1);
        pq.push(top2);
    }
    
    while(!pq.empty()) {
        int work = pq.top(); pq.pop();
        answer += pow((long long)work, 2);
    }
    
    return answer;
}