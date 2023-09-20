#include <bits/stdc++.h>
using namespace std;

const int MAX = 1500 + 5;
#define x first
#define y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
string board[MAX];
bool vis[MAX][MAX];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pair<int, int> swan1, swan2;
    queue<pair<int, int>> water;
    int cnt = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {
                if (cnt == 0) {
                    swan1 = { i, j };
                    cnt++;
                }
                else {
                    swan2 = { i, j };
                }
            }
            if (board[i][j] == '.' || board[i][j] == 'L') {
                water.push({ i, j });
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(swan1);
    vis[swan1.x][swan1.y] = true;

    int phase = 0;
    while (1) {
        queue<pair<int, int>> nxtq;
        bool flag = false;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            
            if (cur == swan2) {
                flag = true;
                break;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny]) continue;

                vis[nx][ny] = true;
                if (board[nx][ny] == 'X') {
                    nxtq.push({ nx, ny });
                }
                else {
                    q.push({ nx, ny });
                }
            }
        }

        if (flag) break;

        q = nxtq;

        int sz = water.size();
        while (sz--) {
            pair<int, int> cur = water.front();
            water.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if (board[nx][ny] == 'X') {
                    board[nx][ny] = '.';
                    water.push({ nx, ny });
                }
            }
        }

        phase++;
    }

    cout << phase << '\n';
    return 0;
}   