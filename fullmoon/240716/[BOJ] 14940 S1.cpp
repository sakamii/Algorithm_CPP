#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x, dist;
	bool operator<(Coord right) const {
		return dist > right.dist;
	}
};

int map[1002][1002];
int dist[1002][1002];
bool visited[1002][1002];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	Coord start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dist[i][j] = 1e7;
			if (map[i][j] == 2) {
				start = { i, j, 0 };
				dist[i][j] = 0;
			}
			else if (map[i][j] == 0) {
				dist[i][j] = 0;
			}
		}
	}
	int max_size = n * m;
	priority_queue<Coord> pq;
	pq.push(start);
	int cnt = 0;
	while (!pq.empty()) {
		Coord now = pq.top();
		pq.pop();

		if (visited[now.y][now.x]) continue;
		visited[now.y][now.x] = true;
		cnt++;

		if (cnt >= max_size) break;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 0) continue;
			int nd = now.dist + 1;
			if (dist[ny][nx] <= nd) continue;
			dist[ny][nx] = nd;
			pq.push({ ny, nx, nd });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 1e7) {
				cout << -1 << " ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
