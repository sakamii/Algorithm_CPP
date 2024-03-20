
#include <iostream>
#include <queue>
#include <tuple>
#define pii pair<int, int>
#define tup tuple<int, int, int>
using namespace std;

int n, t, ans, s[101][101][4];
int dx[] = { 0,0,-1,0,1 }, dy[] = { 0,1,0,-1,0 };
int sign[13][3] = {
	{}, { 1,2,4 }, { 2,1,3 }, { 3,2,4 }, { 4,1,3, },
	{ 1,2,-1 }, { 2,3,-1 }, { 3,4,-1 }, { 4,1,-1 },
	{ 1,4,-1 }, { 2,1,-1 }, { 3,2,-1 }, { 4,3,-1 }
};
bool vis[101][101][101][5];

bool can(int dir, int nsino) {
	if (dir % 4 == nsino % 4) return true;
	else return false;
}

void bfs() {
	queue<tup> q;
	queue<int> tq;
	vis[1][1][0][2] = 1;
	q.push(tup(1, 1, 2));
	tq.push(0);


	while (!q.empty()) {
		tup cur = q.front(); q.pop();
		int x = get<0>(cur), y = get<1>(cur), d = get<2>(cur);
		int ct = tq.front(); tq.pop();

		int cs = s[x][y][ct % 4];
		//cout << x << " " << y << " " << ct << " " << d << "\n";
		if (d != sign[cs][0]) continue;

		for (int i = 0; i < 3; i++) {
			if (sign[cs][i] < 0) continue;
			int nx = x + dx[sign[cs][i]], ny = y + dy[sign[cs][i]];

			//if (d != s[nx][ny][0]) break;

			if (!nx || !ny || nx > n || ny > n) continue;

			if (!vis[nx][ny][ct + 1][sign[cs][i]] && ct + 1 <= t) {
				vis[nx][ny][ct + 1][sign[cs][i]] = 1;
				q.push(tup(nx, ny, sign[cs][i]));
				tq.push(ct + 1);
			}
		}
	}
}


int main() {
	cin >> n >> t;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k < 4; k++)
				cin >> s[i][j][k];

	bfs();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int tt = 0; tt <= t; tt++) {
				bool flag = 0;
				for (int k = 1; k <= 4; k++)
					if (vis[i][j][tt][k]) {
						ans++;
						flag = 1;
						break;
					}
				if (flag) break;
			}

	cout << ans;
}
