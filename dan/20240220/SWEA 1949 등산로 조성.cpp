#include <iostream>
using namespace std;
int t, n, k, ans = 0, maxn = 0;
int map[9][9];
int visited[9][9];
int ydir[] = { -1, 0,1,0 };
int xdir[] = { 0,1,0,-1 };
void dfs(int y, int x, int k_cnt, int len) {
	if (len > ans)ans = len;
	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];
		if (visited[ny][nx] == 1)continue;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (map[y][x] <= map[ny][nx]) {
			if (k_cnt == 0) {
				for (int depth = 1; depth <= k; depth++) {
					map[ny][nx] -= depth;
					if (map[y][x] > map[ny][nx]) {
						visited[ny][nx] = 1;
						dfs(ny, nx, k_cnt+1, len+1);
						visited[ny][nx] = 0;
					}
					map[ny][nx] += depth;
				}
			}
		}
		else {
			visited[ny][nx] = 1;
			dfs(ny, nx, k_cnt, len + 1);
			visited[ny][nx] = 0;
		}
	}
}

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		maxn = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				maxn = max(map[i][j], maxn);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maxn) {
					visited[i][j] = 1;
					dfs(i, j, 0, 1);
					visited[i][j] = 0;
				}
			}
		}
		cout << "#" << tc << " " << ans << endl;
	}
}
