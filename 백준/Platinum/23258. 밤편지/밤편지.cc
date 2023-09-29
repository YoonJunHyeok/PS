#include <bits/stdc++.h>
using namespace std;

const int MAX = 987654321;
int N, Q, c, s, e;
int dp[303][303][303]; // from, to, minimum

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dp[i][j][0];
            if (dp[i][j][0] == 0 && i != j) {
                dp[i][j][0] = MAX;
            }
        }
    }

    for (int x = 1; x <= N; x++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j][x] = min(dp[i][j][x - 1], dp[i][x][x - 1] + dp[x][j][x - 1]);
            }
        }
    }

    while (Q--) {
        cin >> c >> s >> e;
        if (dp[s][e][c - 1] == MAX) {
            cout << "-1\n";
        }
        else {
            cout << dp[s][e][c - 1] << '\n';
        }
    }
    return 0;
}   