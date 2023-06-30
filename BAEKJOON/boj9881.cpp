#include <bits/stdc++.h>
using namespace std;

int N, tmp;
int answer = INT_MAX;
vector<int> elevation;

int calc(int minimum) {
	int maximum = minimum + 17;
	int tmp_answer = 0;
	
	for (int i = 0; i < N; i++) {
		if (elevation[i] < minimum) {
			tmp_answer += pow ((elevation[i] - minimum), 2);
		}
		else if (elevation[i] > maximum) {
			tmp_answer += pow ((maximum - elevation[i]), 2);
		}
	}
	
	return tmp_answer;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		elevation.push_back(tmp);
	}
	
	sort(elevation.begin(), elevation.end());
	
	// 0~17 / 1~18 / ... / 83~100
	for (int i = 0; i <= 83; i++) {
		int tmp_answer = calc(i);
		answer = min(answer, tmp_answer);
	}
	
	cout << answer << "\n";
	return 0;
}
