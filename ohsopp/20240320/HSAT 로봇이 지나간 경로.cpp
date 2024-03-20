
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int h, w, sx, sy, dir;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };	// 위오아왼
string s[27];
char chs[4] = { '^', '>', 'v', '<' };
vector<int> path;

int main() {
	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		string str;
		cin >> str;
		s[i] = "x" + str;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (s[i][j] == '#') {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d], ny = j + dy[d];

					if (!nx || !ny || nx > h || ny > w) continue;

					cnt += (s[nx][ny] == '#');
					if (s[nx][ny] == '#') dir = d;
				}

				if (cnt < 2) {
					sx = i;
					sy = j;
					cout << sx << " " << sy << '\n' << chs[dir] << '\n';
					break;
				}
			}
		}
		if (sx && sy) break;
	}

	while (1) {
		bool flag = 0;

		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i], ny = sy + dy[i];

			if (!nx || !ny || nx > h || ny > w) continue;

			if (s[nx][ny] == '#') {
				flag = 1;
				if (i == dir) {
					s[nx][ny] = '.';
					sx += dx[i] * 2;
					sy += dy[i] * 2;
					cout << 'A';
				}
				else if ((dir + 1) % 4 == i) cout << 'R';
				else cout << 'L';

				dir = i;
				break;
			}
		}

		if (!flag) break;
	}
}
