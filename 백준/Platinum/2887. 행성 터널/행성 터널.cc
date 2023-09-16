#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 100000 + 1;
int N;
vector<pair<int, int>> X, Y, Z;
vector<tuple<int, int, int>> road;
int parent[MAX];

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    parent[x] = y;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back({ x, i });
        Y.push_back({ y, i });
        Z.push_back({ z, i });
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N - 1; i++) {
        road.push_back({ X[i + 1].first - X[i].first, X[i + 1].second, X[i].second });
        road.push_back({ Y[i + 1].first - Y[i].first, Y[i + 1].second, Y[i].second });
        road.push_back({ Z[i + 1].first - Z[i].first, Z[i + 1].second, Z[i].second });
    }
    sort(road.begin(), road.end());

    int answer = 0, cnt = 0;
    for (int i = 0; i < road.size(); i++) {
        int cost, x, y;
        tie(cost, x, y) = road[i];
        if (find(x) == find(y)) continue;
        Union(x, y);
        answer += cost;
        cnt++;
        if (cnt == N - 1) break;
    }

    cout << answer << '\n';
    return 0;
}