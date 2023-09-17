#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, p;
    long long ans = 0;
    stack<pair<int, int>> s;
    cin >> N;
    while (N--) {
        cin >> p;

        while (!s.empty() && s.top().first < p) {
            ans += s.top().second;
            s.pop();
        }

        if (s.empty()) {
            s.push({ p, 1 });
        }
        else {
            if (s.top().first == p) {
                pair<int, int> cur = s.top();
                s.pop();
                ans += cur.second;
                if (!s.empty()) ans++;
                cur.second++;
                s.push(cur);
            }
            else {
                s.push({ p, 1 });
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}