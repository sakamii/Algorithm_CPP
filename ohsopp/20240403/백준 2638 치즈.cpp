
#include <iostream>
#include <queue>
#include <memory.h>
#define pii pair<int, int>
using namespace std;

int n, m, ans, cnt, v[101][101];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
bool vis[101][101];

void bfs(int X, int Y) {
	memset(vis, 0, sizeof(vis));
	queue<pii> q;
	q.push({ X,Y });
	vis[X][Y] = 1;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (!nx || !ny || nx > n || ny > m) continue;

			if (!vis[nx][ny] && v[nx][ny] != 1) {
				vis[nx][ny] = 1;
				v[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			cnt += v[i][j];
		}

	queue<pii> vq;
	while (cnt) {
		bfs(1, 1);
		for (int i = 2; i < n; i++)
			for (int j = 2; j < m; j++)
				if (v[i][j] == 1) {
					int c = 0;
					for (int k = 0; k < 4; k++)
						c += (v[i + dx[k]][j + dy[k]] == 2);
					if (c >= 2) vq.push({ i,j });
				}

		cnt -= vq.size();
		while (!vq.empty()) {
			v[vq.front().first][vq.front().second] = 2;
			vq.pop();
		}
		ans++;
	}
	cout << ans;
}
