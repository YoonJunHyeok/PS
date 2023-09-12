#include <bits/stdc++.h>
using namespace std;

int N, K, tmp;
vector<int> num; // 크기순서
vector<int> order; // 먼저들어갈순서( = 맨 앞 숫자 큰 순서)
string ans = "";

bool cmp1(int a, int b) {
	return a > b;
}

bool cmp2(int a, int b) {
	string tmpa = to_string(a) + to_string(b);
	string tmpb = to_string(b) + to_string(a);

	return tmpa > tmpb;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
		order.push_back(tmp);
	}
	sort(num.begin(), num.end(), cmp1);
	sort(order.begin(), order.end(), cmp2);
	
	if (N == K) {
		for (int i = 0; i < N; i++) {
			ans += to_string(order[i]);
		}
	}
	else {
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (order[i] == num[0]) {
				if (flag) ans += to_string(order[i]);
				else {
					for (int j = 0; j < K - N + 1; j++) {
						ans += to_string(order[i]);
					}
					flag = true;
				}
			}
			else {
				ans += to_string(order[i]);;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}