#include <bits/stdc++.h>
using namespace std;

int N, R, tmp;
bool survived[10001];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> R;
	for (int i = 1; i <= R; i++) {
		cin >> tmp;
		survived[tmp] = true;			
	}
	
	if (N == R) {
		cout << "*";
		
	}
	else {
		for (int i = 1; i <= N; i++) {
			if(!survived[i]) cout << i << " ";
		}	
	}
	
	return 0;
}
