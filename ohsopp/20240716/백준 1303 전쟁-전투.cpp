#include <iostream>
#include <queue>

using namespace std;

int n, m, w, b, v[102][102];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
bool vis[102][102];

void bfs(int X, int Y, int c) {
	vis[X][Y] = 1;
	queue<pair<int, int>> q;
	q.push({ X,Y });
	int wcnt = 0, bcnt = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		if (v[x][y] == 0) wcnt++;
		else bcnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!nx || !ny || nx > n || ny > m) continue;

			if (!vis[nx][ny] && v[nx][ny] == c) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	w += wcnt * wcnt;
	b += bcnt * bcnt;
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
			if (s[j] == 'W') v[i + 1][j + 1] = 0;
			else v[i + 1][j + 1] = 1;
	}

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j])
				bfs(i, j, v[i][j]);

	cout << w << " " << b;
}
