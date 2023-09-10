#include <bits/stdc++.h>
using namespace std;

const int MAX = 987654321;
int N, M, Q, a, b, d, S, T;
int dis[505][505];
int res[505][505];
pair<int, int> adj[505];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 입력
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> adj[i].first;
        adj[i].second = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                dis[i][j] = MAX;
                res[i][j] = MAX;
            }
            else {
                dis[i][j] = adj[i].first;
            }
        }
    }
    while (M--) {
        cin >> a >> b >> d;
        dis[a][b] = d;
        dis[b][a] = d;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) res[i][j] = adj[i].first;
            else res[i][j] = dis[i][j] + max(adj[i].first, adj[j].first);
        }
    }
    sort(adj + 1, adj + N + 1);

    int idx[505];
    for (int i = 1; i <= N; i++) {
        idx[adj[i].second] = i;
    }

    // 플로이드
    for (int t = 1; t <= N; t++) {
        int x = adj[t].second;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dis[i][j] = min(dis[i][j], dis[i][x] + dis[x][j]);
                res[i][j] = min(res[i][j], dis[i][x] + dis[x][j] + max(adj[idx[i]].first, max(adj[idx[x]].first, adj[idx[j]].first)));
            }
        }
    }

    // 출력
    while (Q--) {
        cin >> S >> T;
        if (res[S][T] >= MAX) cout << -1 << '\n';
        else cout << res[S][T] << '\n';
    }
    return 0;
}   