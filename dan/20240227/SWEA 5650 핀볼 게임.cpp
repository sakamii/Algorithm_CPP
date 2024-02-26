#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, ans, maxans;
int sy, sx, flag = 0;
int map[1001][1001];
vector<pair<int, int>> worm[11];
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };

void dfs(int y, int x, int type, int dir) {
	// 만약 이게 -1이거나 시작지점에 돌아왔다면 return
	if (type == -1) return;
	if (y == sy && x == sx)
		if(flag==1)return;
	// 한 번 이상 움직이면 플래그 1로 올려줌 
	flag = 1;
	if (type == 0) {
		// 벽에 부딪힌 경우
		if (y == 0 || y == n - 1 || x == 0 || x == n - 1)ans++;
		int ny = y + ydir[dir];
		int nx = x + xdir[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
		dfs(ny, nx, map[ny][nx], dir);
	}
	else if (type == 1) {
		ans++;
		if (dir == 0) {
			int ny = y + ydir[1];
			int nx = x + xdir[1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 1);
		}
		if (dir == 1) {
			int ny = y + ydir[3];
			int nx = x + xdir[3];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 3);
		}
		if (dir == 2) {
			int ny = y + ydir[0];
			int nx = x + xdir[0];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 0);
		}
		if (dir == 3) {
			int ny = y + ydir[2];
			int nx = x + xdir[2];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 2);
		}
	}
	else if (type == 2) {
		ans++;
		if (dir == 0) {
			int ny = y + ydir[3];
			int nx = x + xdir[3];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 3);
		}
		if (dir == 1) {
			int ny = y + ydir[0];
			int nx = x + xdir[0];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 0);
		}
		if (dir == 2) {
			int ny = y + ydir[1];
			int nx = x + xdir[1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 1);
		}
		if (dir == 3) {
			int ny = y + ydir[2];
			int nx = x + xdir[2];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 2);
		}
	}
	else if (type == 3) {
		ans++;
		if (dir == 0) {
			int ny = y + ydir[2];
			int nx = x + xdir[2];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 2);
		}
		if (dir == 1) {
			int ny = y + ydir[0];
			int nx = x + xdir[0];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 0);
		}
		if (dir == 2) {
			int ny = y + ydir[3];
			int nx = x + xdir[3];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 3);
		}
		if (dir == 3) {
			int ny = y + ydir[1];
			int nx = x + xdir[1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 1);
		}
	}
	else if (type == 4) {
		ans++;
		if (dir == 0) {
			int ny = y + ydir[1];
			int nx = x + xdir[1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 1);
		}
		if (dir == 1) {
			int ny = y + ydir[2];
			int nx = x + xdir[2];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 2);
		}
		if (dir == 2) {
			int ny = y + ydir[3];
			int nx = x + xdir[3];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 3);
		}
		if (dir == 3) {
			int ny = y + ydir[0];
			int nx = x + xdir[0];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 0);
		}
	}
	else if (type == 5) {
		ans++;
		if (dir == 0) {
			int ny = y + ydir[1];
			int nx = x + xdir[1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 1);
		}
		if (dir == 1) {
			int ny = y + ydir[0];
			int nx = x + xdir[0];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 0);
		}
		if (dir == 2) {
			int ny = y + ydir[3];
			int nx = x + xdir[3];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 3);
		}
		if (dir == 3) {
			int ny = y + ydir[2];
			int nx = x + xdir[2];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)return;
			dfs(ny, nx, map[ny][nx], 2);
		}
	}
	else if (type >= 6) {
		if (y == worm[type][0].first && x == worm[type][0].second) {
			int ny = worm[type][1].first;
			int nx = worm[type][1].second;
			dfs(ny, nx, 0, dir);
		}
		else {
			int ny = worm[type][0].first;
			int nx = worm[type][0].second;
			dfs(ny, nx, 0, dir);
		}
	}
}

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		maxans = 0;
		cin >> n;
		worm->clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6) {
					worm[map[i][j]].push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int type = map[i][j];
				sy = i; sx = j;
				if (type == 0) {
					for (int k = 0; k < 4; k++) {
						flag = 0;
						ans = 0;
						dfs(i, j, 0, k);
						maxans = max(maxans, ans);
					}
				}
			}
		}
		cout <<"#"<<tc<<" "<< ans<<endl;
	}
}
