#include<iostream>
#include<queue>
using namespace std;

int map[51][51] = { 0 };
int visited[51][51] = { 0 };

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };

int t, m, n, k;
int cnt = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push(pair<int,int>(nx, ny));
			}
		}
	}
}

void init() {
	cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visited[i][j] = 1;
		}
	}
}

int main() {
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b; // 배추가 심어져 있는 위치에 대한 좌표
			map[a][b] = 1;
		}
		for (int j = 0; j < m; j++) {
			for (int t = 0; t < n; t++) {
				if (map[j][t] == 1 && visited[j][t] == 0) {
					bfs(j, t);
					cnt++;
				}
			}
		}
		cout << cnt;
		cout << endl;
		init();
		

	}
}
