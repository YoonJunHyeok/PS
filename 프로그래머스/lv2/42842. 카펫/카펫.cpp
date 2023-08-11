#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    
    for(int i = 3; i * i <= total; i++) {
        if(total % i != 0) continue;
        int j = total / i;
        if(yellow == (i - 2) * (j - 2)) {
            answer.push_back(i);
            answer.push_back(j);
            break;
        }
    }
    
    sort(answer.begin(), answer.end(), greater<>());
        
    return answer;
}