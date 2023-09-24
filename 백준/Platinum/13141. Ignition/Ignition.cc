#include <bits/stdc++.h>
using namespace std;

const int MAX = 987654321;
int N, M, s, e, l;
int dis[202][202];
int adj[202][202];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = -1;
            if (i == j) continue;
            dis[i][j] = MAX;
        }
    }

    while (M--) {
        cin >> s >> e >> l;
        if (dis[s][e] > l) {
            dis[s][e] = l;
            dis[e][s] = l;
        }
        if (adj[s][e] < l) {
            adj[s][e] = l;
            adj[e][s] = l;
        }
    }

    for (int x = 1; x <= N; x++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dis[i][j] > dis[i][x] + dis[x][j]) {
                    dis[i][j] = dis[i][x] + dis[x][j];
                }
            }
        }
    }

    double ans = DBL_MAX;
    for (int x = 1; x <= N; x++) {
        double tmp = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int edge = adj[i][j];
                if (edge == -1) continue;
                double remain = edge - (dis[x][j] - dis[x][i]);
                if (remain <= 0) continue;
                double total = remain / 2 + dis[x][j];
                tmp = max(tmp, total);
            }
        }
        ans = min(ans, tmp);
    }

    cout << fixed;
    cout.precision(1);
    cout << ans << '\n';
    return 0;
}   