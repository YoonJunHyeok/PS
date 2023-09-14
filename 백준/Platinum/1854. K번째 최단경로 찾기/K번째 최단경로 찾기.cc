#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 1001

int N, M, K, a, b, c;
vector<pair<int, int>> adj[MAX];
priority_queue<int> dis[MAX];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    while (M--) {
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });
    dis[1].push(0);

    while (!pq.empty()) {
        int len = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (auto idx : adj[cur]) {
            int nxtlen = idx.first + len;
            int nxt = idx.second;
            if (dis[nxt].size() < K) {
                dis[nxt].push(nxtlen);
                pq.push({ nxtlen, nxt });
            }
            else if (dis[nxt].top() > nxtlen) {
                dis[nxt].pop();
                dis[nxt].push(nxtlen);
                pq.push({ nxtlen, nxt });
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dis[i].size() < K) {
            cout << "-1\n";
        }
        else {
            cout << dis[i].top() << '\n';
        }
    }
    return 0;
}