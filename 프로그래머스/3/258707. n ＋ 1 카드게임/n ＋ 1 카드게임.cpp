#include <string>
#include <vector>
#include <set>

using namespace std;

int N;

bool check(set<int> &l, set<int> &r) {
    for(int n: l) {
        if(r.find(N + 1 - n) != r.end()){
            l.erase(n);
            r.erase(N + 1 - n);
            return true;
        }
     }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    set<int> initial, additional;
    N = cards.size();
    
    for(int i = 0; i < N / 3; i++) {
        initial.insert(cards[i]);
    }
    
    int idx = N / 3;
    while(idx < N) {
        for(int i = 0; i < 2; i++) {
            additional.insert(cards[idx++]);
        }
        
        if(initial.size() >= 2 && check(initial, initial)) {
            answer++;
        }
        else if(initial.size() >= 1 && coin >= 1 && check(initial, additional)) {
            answer++;
            coin--;
        }
        else if(coin >= 2 && check(additional, additional)) {
            answer++;
            coin -= 2;
        }
        else {
            break;
        }
    }
    
    
    return answer;
}