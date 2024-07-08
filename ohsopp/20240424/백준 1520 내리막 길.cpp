
#include <iostream>
using namespace std;

int n, m, v[501][501];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int memo[501][501];

int dfs(int x, int y) {

	if (x == n && y == m) return 1;

	if (memo[x][y] > -1) return memo[x][y];

	memo[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx && ny && nx <= n && ny <= m && v[x][y] > v[nx][ny]) memo[x][y] += dfs(nx, ny);
	}

	return memo[x][y];
}

int main() {
	cin >> n >> m;
	fill(memo[0], memo[501], -1);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> v[i][j];

	cout << dfs(1, 1);
}
