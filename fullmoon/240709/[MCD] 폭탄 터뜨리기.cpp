#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;
	char map[22][22];
	vector<pair<int, int>> bomb;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@') {
				bomb.push_back({ i, j });
			}
		}
	}
	int dy[4] = { -1, 0, 1, 0 };
	int dx[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < bomb.size(); i++) {
		int y = bomb[i].first;
		int x = bomb[i].second;
		map[y][x] = '%';
		for (int j = 0; j < 4; j++) {
			for (int k = 1; k <= K; k++) {
				int ny = y + dy[j] * k;
				int nx = x + dx[j] * k;
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == '#') break;
				map[ny][nx] = '%';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}
