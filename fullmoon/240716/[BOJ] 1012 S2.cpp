#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Coord {
	int y, x, area;
};

int M, N, K;
int map[52][52];
bool visited[52][52] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue<Coord> point;

void bfs(int y, int x) {
	queue<Coord> q;
	q.push({ y, x });
	visited[y][x] = true;
	while (!q.empty()) {
		Coord now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			if (!map[ny][nx]) continue;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
			point.push({ y, x });
		}

		int ans = 0;
		while (!point.empty()) {
			Coord now = point.front();
			point.pop();
			if (visited[now.y][now.x]) continue;
			ans++;
			bfs(now.y, now.x);
		}
		cout << ans << "\n";
	}

	return 0;
}
