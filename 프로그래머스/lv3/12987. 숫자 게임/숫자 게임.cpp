#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int len = A.size();
    priority_queue<int, vector<int>, greater<int>> pqA(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> pqB(B.begin(), B.end());
    
    while(!pqA.empty()) {
        int a = pqA.top();
        pqA.pop();
        
        while(!pqB.empty()) {
            int b = pqB.top();
            pqB.pop();
            if(b > a) {
                answer++;
                break;
            }
        }
    }
    
    return answer;
}