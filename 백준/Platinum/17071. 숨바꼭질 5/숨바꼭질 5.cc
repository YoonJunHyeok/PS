#include <bits/stdc++.h>
using namespace std;

const int lmt = 500000;
int board[lmt + 2];
int vis[2][lmt + 2];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    queue<pair<int, int>> q;
    memset(vis, -1, sizeof(vis));
    int n, k, ans = 0;
    cin >> n >> k;

    q.push({ n, 0 });
    vis[0][n] = 0;

    while(!q.empty()) {
        int v, vt, nvt;
        tie(v, vt) = q.front(); q.pop();
        nvt = vt + 1;
        
        for (int nv : {v * 2, v + 1, v - 1}) {
            if (nv >= 0 && nv <= lmt) {
                if (vis[nvt % 2][nv] == -1) {
                    vis[nvt % 2][nv] = nvt;
                    q.push({ nv, nvt });
                }
            }
        }
    }

    bool found = false;

    while (k <= lmt) {
        if (vis[ans % 2][k] <= ans) {
            found = true;
            break;
        }
        k += ++ans;
    }

    if (found) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}