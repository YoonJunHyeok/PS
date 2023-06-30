#include <bits/stdc++.h>
using namespace std;

int H, W, X, Y;
int A[300][300], B[600][600];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}
	
	// i: X ~ H, j: Y ~ W is overwritten
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i >= X && j >= Y) {
				A[i][j]= B[i][j] - A[i - X][j - Y];
			}	
			else {
				A[i][j] = B[i][j];
			}	
		}	
	} 
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
