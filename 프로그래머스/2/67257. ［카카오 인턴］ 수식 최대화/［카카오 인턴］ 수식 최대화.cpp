#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<char> prior{'+', '-', '*'};
vector<long long> nums;
vector<char> ops;

void init(string exp) {
    string tmp = "";
    for(int i = 0; i < exp.length(); i++) {
        if(isdigit(exp[i])) {
            tmp += exp[i];
        }
        else {
            ops.push_back(exp[i]);
            nums.push_back((long long)stoi(tmp));
            tmp = "";
        }
    }
    nums.push_back((long long)stoi(tmp));
}

long long cal(char op, long long a, long long b) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    
    init(expression);
    sort(prior.begin(), prior.end());
    
    do {
        vector<long long> tmpNums = nums;
        vector<char> tmpOps = ops;
        
        for(char op: prior) {
            for(int idx = 0; idx < tmpOps.size(); idx++) {
                if(op == tmpOps[idx]) {
                    tmpNums[idx] = cal(op, tmpNums[idx], tmpNums[idx + 1]);
                    tmpNums.erase(tmpNums.begin() + idx + 1);
                    tmpOps.erase(tmpOps.begin() + idx);
                    idx--;
                }
            }
        }
        
        answer = max(answer, abs(tmpNums[0]));        
    } while(next_permutation(prior.begin(), prior.end()));
    
    return answer;
}