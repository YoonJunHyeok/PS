#include <bits/stdc++.h>
#include <queue>
using namespace std;

int N, tmp, accumulate_time;
queue < pair<int,int> > q; // (idx, remain number of slices of pizza) 
int answer[1001];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> tmp;
		q.push(pair<int,int>(i, tmp));
	}
	
	while(!q.empty()) {
		accumulate_time++;
		int idx = q.front().first;
		int n = q.front().second;
		q.pop();
		n--;
		
		if(n == 0) {
			answer[idx] = accumulate_time;
		}
		else {
			q.push(pair<int,int>(idx, n));
		}		
	}
	
	for(int i = 1; i <= N; i++) {
		cout << answer [i] << " ";
	}
	
	return 0;
}
