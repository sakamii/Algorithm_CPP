#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;
int house[17][17] = { 0 };
int t, n, m, ans = 0;
int visited[17][17] = { 0 };
void dfs(int y, int x, int sum, int cnt) {
	if (cnt == 4) {
		// 개중에 가장 큰 sum 내보냄
		ans = max(ans, sum);
		return;
	}
	// 만약에 들어온 수가 홀수열일때
	if (x % 2 == 1) {
		int ydir[] = { 0,-1,-1,-1,0,1 };
		int xdir[] = { -1,-1,0,1,1,0 };
		for (int i = 0; i < 6; i++) {
			int ny = y + ydir[i];
			int nx = x + xdir[i];
			if (ny < 1 || ny > n || nx < 1 || nx > m)continue;
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			dfs(ny, nx, sum + house[ny][nx], cnt+1);
			visited[ny][nx] = 0;
		}
	}
	// 그게 아니라 짝수열에 있을때
	else {
		int ydir[] = { 0,1,-1,1,0,1 };
		int xdir[] = { -1,-1,0,1,1,0 };
		for (int i = 0; i < 6; i++) {
			int ny = y + ydir[i];
			int nx = x + xdir[i];
			if (ny < 1 || ny > n || nx < 1 || nx > m)continue;
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			dfs(ny, nx, sum + house[ny][nx], cnt+1);
			visited[ny][nx] = 0;
		}
	}
}

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		cin >> n >> m;
		fill(house[0], house[17], 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> house[i][j];
			}
		}
		// 피젯 모양을 전부 돌면서 max값을 연동함
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j % 2) {
					ans = max(ans, house[i][j] + house[i][j - 1] + house[i][j + 1] + house[i - 1][j]);
					ans = max(ans, house[i][j] + house[i - 1][j - 1] + house[i - 1][j + 1] + house[i + 1][j]);
				}
				else {
					ans = max(ans, house[i][j] + house[i][j - 1] + house[i][j + 1] + house[i + 1][j]);
					ans = max(ans, house[i][j] + house[i + 1][j - 1] + house[i + 1][j + 1] + house[i - 1][j]);
				}
				// dfs로 최대값 찾기
				visited[i][j] = 1;
				dfs(i, j, house[i][j], 1);
				visited[i][j] = 0;
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}
}
