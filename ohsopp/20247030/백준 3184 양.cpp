
#include <iostream>
#include <queue>
using namespace std;

int r, c, A, B, yard[252][252];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
bool vis[252][252];

void bfs(int X, int Y) {

	vis[X][Y] = 1;
	queue<pair<int, int>> q;
	q.push({ X,Y });

	int a = 0, b = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		if (yard[x][y] == 2) a++;
		else if (yard[x][y] == 3) b++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (!nx || !ny || nx > r || ny > c) continue;

			if (!vis[nx][ny] && yard[nx][ny] != 1) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	if (a > b) B -= b;
	else A -= a;
}

int main() {
	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		string s;
		cin >> s;

		for (int j = 1; j <= c; j++) {
			if (s[j] == '.') yard[i][j] = 0;
			else if (s[j] == '#') yard[i][j] = 1;
			else if (s[j] == 'o') yard[i][j] = 2, A++;
			else if (s[j] == 'v') yard[i][j] = 3, B++;
		}
	}

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (!vis[i][j] && yard[i][j] != '1')
				bfs(i, j);


	cout << A << " " << B;
}
