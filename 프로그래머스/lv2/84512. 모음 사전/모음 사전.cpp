#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
int idx = 1;
vector<string> alpha = {"A", "E", "I", "O", "U"};

void work(string cur, int N) {
    if (N == 6) return;
    for(int i = 0; i < 5; i++) {
        string tmp = cur + alpha[i];
        m[tmp] = idx++;
        work(tmp, N + 1);
    }
}

int solution(string word) {
    int answer = 0;   
    
    work("", 1);
    
    answer = m[word];
    return answer;
}