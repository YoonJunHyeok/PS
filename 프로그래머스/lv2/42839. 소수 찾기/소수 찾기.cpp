#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000000;

int solution(string numbers) {
    int answer = 0;
    vector<bool> is_prime(MAX, true);
    vector<char> number;
    vector<int> candidates;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= MAX; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for(int i = 0; i < numbers.size(); i++) {
        number.push_back(numbers[i]);
    }
    sort(number.begin(), number.end());
    
    do {
        string tmp = "";
        for(int i = 0; i < number.size(); i++) {
            tmp.push_back(number[i]);
            candidates.push_back(stoi(tmp));
        }
    } while(next_permutation(number.begin(), number.end()));
    
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    
    for(int i = 0; i < candidates.size(); i++) {
        if(is_prime[candidates[i]]) answer++;
    }
    
    return answer;
}