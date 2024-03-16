#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m[2]; // key: score, value: num
vector<int> selectDice[2];
vector<vector<int>> cdice;
int N; // 전체 dice 개수

void dfs(int personIdx, int diceIdx, int score) {
    if(diceIdx == N / 2) { // 모든 주사위 이용완료
        m[personIdx][score]++; // map에 해당 스코어 하나 더 만들 수 있다고 기록
        return;
    }

    for(int i = 0; i < 6; i++) {
        int curDiceScore = cdice[selectDice[personIdx][diceIdx] - 1][i]; // 왜 굳이 밑에서 +1을 해서 여기서 귀찮게 -1을 하게 만든걸까
        dfs(personIdx, diceIdx + 1, score + curDiceScore); // 다음 주사위 index 선택하면서 score 갱신
    }
}

int cal() { // 현재 조합으로 A가 이길 수 있는 모든 경우의 수 return
    int cnt = 0;
    for(auto it1 = m[0].begin(); it1 != m[0].end(); it1++) {
        for(auto it2 = m[1].begin(); it2 != m[1].end(); it2++) {
            if(it1->first > it2->first) {
                cnt += (it1->second * it2->second); // A의 점수를 만드는 경우의 수 * B의 점수를 만드는 경우의 수
            }
            else break; // map은 오름차순이기에 지금 B의 score를 이길 수 없다면, 그 뒤의 score는 확실하게 이기지 못한다. 
        }
    }
    return cnt;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    cdice = dice;
    N = dice.size();
    vector<int> combination;
    for(int i = 1; i <= N / 2; i++) {
        combination.push_back(0);
    }
    for(int i = 1; i <= N / 2; i++) {
        combination.push_back(1);
    }

    int cur_win_number = -1;
    do {
				// 초기화
        for(int i = 0; i < 2; i++) {
            selectDice[i].clear();
            m[i].clear();
        }

        for(int i = 0; i < N; i++) {
						// i번째 combination vector의 값이 1이면 A의 주사위 리스트에 i+1 을 추가한다.
            if(combination[i]) selectDice[0].push_back(i + 1);
            else selectDice[1].push_back(i + 1);
        }

        dfs(0, 0, 0); // 현재 A가 선택한 주사위들로 만들 수 있는 모든 각각의 score들의 경우의 수 구하기
        dfs(1, 0, 0); // 22

        int win_number = cal();
        if(cur_win_number < win_number) {
            answer = selectDice[0];
            cur_win_number = win_number;
        }
    } while(next_permutation(combination.begin(), combination.end()));

    return answer;
}