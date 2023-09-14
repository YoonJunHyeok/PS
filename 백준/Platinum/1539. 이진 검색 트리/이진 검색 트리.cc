#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<int, int> m;
    int N;
    long long sum = 0;

    cin >> N;
    while (N--) {
        int tmp; cin >> tmp;

        if (m.empty()) {
            m[tmp] = 1;
            sum += 1;
        }
        else {
            auto itr = m.lower_bound(tmp);
            int height;

            if (itr == m.begin()) {
                height = itr->second + 1;
            }
            else if (itr == m.end()) {
                height = prev(itr)->second + 1;
            }
            else {
                height = max(itr->second + 1, prev(itr)->second + 1);
            }

            m[tmp] = height;
            sum += height;
        }
    }

    cout << sum << '\n';
    return 0;
}