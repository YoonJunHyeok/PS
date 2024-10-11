#include <bits/stdc++.h>
using namespace std;

struct info {
	int speed;
	int direction;
	int sz;
};

int dx[5] = {0, -1, 1, 0, 0 };
int dy[5] = {0, 0, 0, 1, -1 };
int R, C, M, r, c, s, d, z;
vector<info> board[101][101];
int angler = 0;
int answer = 0;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> M;
	while (M--) {
		cin >> r >> c >> s >> d >> z;
		board[r][c].push_back({s, d, z});
	}
	
	while (angler < C) {
		// 1.
		angler++;

		// 2.
		for (int i = 1; i <= R; i++) {
			if (board[i][angler].empty()) continue;

			answer += board[i][angler][0].sz;
			board[i][angler].clear();
			break;
		}

		// 3.
		queue<pair<pair<int, int>, info>> q;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (board[i][j].empty()) continue;
				q.push({ {i, j}, board[i][j][0] });
				board[i][j].clear();
			}
		}

		while (!q.empty()) {
			int curx = q.front().first.first, cury = q.front().first.second;
			info tmp = q.front().second;
			q.pop();

			if (tmp.direction == 1 || tmp.direction == 2) {
				int sp = tmp.speed % ((R - 1) * 2);
				while (sp--) {
					int nx = curx + dx[tmp.direction];
					if (nx < 1 || nx > R) {
						tmp.direction = 3 - tmp.direction;
					}
					curx += dx[tmp.direction];					
				}
			}
			else {
				int sp = tmp.speed % ((C - 1) * 2);
				while (sp--) {
					int ny = cury + dy[tmp.direction];
					if (ny < 1 || ny > C) {
						tmp.direction = 7 - tmp.direction;
					}
					cury += dy[tmp.direction];					
				}
			}

			if (board[curx][cury].empty()) {
				board[curx][cury].push_back(tmp);
			}
			else {
				if (board[curx][cury][0].sz < tmp.sz) {
					board[curx][cury].clear();
					board[curx][cury].push_back(tmp);
				}
			}
		}
	}

	cout << answer << '\n';
	return 0;
}