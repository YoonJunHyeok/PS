#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int tmpL = 0, tmpR = 0, cur = sequence[0], ansL = -1, ansR = sequence.size();
    
    while(tmpR < sequence.size() && tmpL <= tmpR) {
        if(cur == k) {
            if(tmpR - tmpL < ansR - ansL) {
                ansR = tmpR;
                ansL = tmpL;
            }
        }
        
        if(cur >= k) {
            cur -= sequence[tmpL];
            tmpL++;
        }
        else {
            tmpR++;
            cur += sequence[tmpR];
        }
    }
    
    vector<int> answer = {ansL, ansR};
    return answer;
}