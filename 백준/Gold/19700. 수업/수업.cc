#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, h, k;
    cin >> N;

    vector<int> v;
    priority_queue <pair<int, int>> pq;

    for (int i = 0; i < N; i++) {
        cin >> h >> k;
        pq.push({ h, k });
    }

    while (N--) {
        int ki = pq.top().second; pq.pop();
        int idx = upper_bound(v.begin(), v.end(), ki, greater<int>()) - v.begin();
        
        if (idx == v.size()) v.push_back(1);
        else v[idx]++;
    }

    cout << v.size() << '\n';
    return 0;
}
//어렵네;;