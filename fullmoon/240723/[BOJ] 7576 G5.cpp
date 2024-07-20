#include <iostream>
#include <queue>
using namespace std;

struct Box {
	int y, x, day;
};

int box[1002][1002];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, N;
	cin >> M >> N;
	int cnt = 0;
	queue<Box> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] != -1) {
				if (box[i][j] == 1) {
					q.push({ i, j, 0 });
				}
				cnt++;
			}
		}
	}
	int dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
	int ans = -1;
	while (!q.empty()) {
		Box now = q.front();
		q.pop();

		if (box[now.y][now.x] == 1) cnt--;
		if (cnt <= 0) {
			ans = now.day;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (box[ny][nx] != 0) continue;
			q.push({ ny, nx, now.day + 1 });
			box[ny][nx] = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
