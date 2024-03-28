
// 양봉업자 코코

#include <iostream>
using namespace std;

int t, n, m, ans, v[17][17];
int dx1[] = { -1,-1,-1,0,1,0 }, dy1[] = { -1,0,1,1,0,-1 };
int dx2[] = { -1,0,1,1,1,0 }, dy2[] = { 0,1,1,0,-1,-1 };
bool vis[17][17];

void dfs(int x, int y, int sum, int d) {
	if (d == 3) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 6; i++) {
		int nx, ny;
		if (y % 2) nx = x + dx1[i], ny = y + dy1[i];
		else nx = x + dx2[i], ny = y + dy2[i];

		if (!nx || !ny || nx > n || ny > m) continue;

		if (!vis[nx][ny]) {
			vis[nx][ny] = 1;
			dfs(nx, ny, sum + v[nx][ny], d + 1);
			vis[nx][ny] = 0;
		}
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		cin >> n >> m;

		fill(v[0], v[17], 0);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> v[i][j];

		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (j % 2) {
					ans = max(ans, v[i][j] + v[i][j - 1] + v[i][j + 1] + v[i - 1][j]);
					ans = max(ans, v[i][j] + v[i - 1][j - 1] + v[i - 1][j + 1] + v[i + 1][j]);
				}
				else {
					ans = max(ans, v[i][j] + v[i][j - 1] + v[i][j + 1] + v[i + 1][j]);
					ans = max(ans, v[i][j] + v[i + 1][j - 1] + v[i + 1][j + 1] + v[i - 1][j]);
				}
				vis[i][j] = 1;
				dfs(i, j, v[i][j], 0);
				vis[i][j] = 0;
			}
		cout << "#" << tc << " " << ans << '\n';
	}
}
