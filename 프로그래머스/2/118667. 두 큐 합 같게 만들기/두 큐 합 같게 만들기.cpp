#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    // 결국, int들의 전체 나열 순서는 똑같다.
    int N = queue1.size();
    vector<int> queue(queue1);
    queue.insert(queue.end(), queue2.begin(), queue2.end());
    
    long long sum = accumulate(queue.begin(), queue.end(), (long long)0);
    long long half = sum / 2;
    
    int start = 0, end = queue1.size() - 1;
    long long cur = accumulate(queue.begin() + start, queue.begin() + end + 1, (long long)0);
    
    while(start < N * 2) {
        if(cur == half) return answer;
        
        if(cur > half || end >= N * 2) {
            cur -= (long long)queue[start++];
        }
        else {
            cur += (long long)queue[++end];
        }
        answer++;
    }
    
    return -1;
}