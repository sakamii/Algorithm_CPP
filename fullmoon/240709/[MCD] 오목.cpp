#include <iostream>
using namespace std;

int map[22][22];

void findLine() {
	int dir[4][2] = { 1, 0, 0, 1, 1, 1, -1, 1 };
	bool visited[4][22][22] = { 0, };
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			int start = map[i][j];
			if (start == 0) continue;
			for (int k = 0; k < 4; k++) {
				int cnt = 1;
				if (visited[k][i][j]) continue;
				visited[k][i][j] = true;
				while (true) {
					int ny = i + dir[k][0] * cnt;
					int nx = j + dir[k][1] * cnt;
					if (ny < 0 || ny > 19 || nx < 0 || ny > 19) break;
					if (map[ny][nx] == start) cnt++;
					else break;
					visited[k][ny][nx] = true;
				}
				if (cnt == 5) {
					cout << start << "\n";
					cout << i << " " << j << "\n";
					return;
				}
			}
		}
	}
	cout << 0 << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> map[i][j];
		}
	}
	findLine();
	return 0;
}
