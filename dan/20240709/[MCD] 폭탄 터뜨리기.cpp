#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
char map[21][21];
int n, m, k;
int dir[2][4] = { {-1,1,0,0},{0,0,-1,1} };
vector<pair<int, int>>bombs;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@') {
				bombs.push_back({ i,j });
				map[i][j] = '%';
			}
		}
	}
	for (int i = 0; i < bombs.size(); i++) {
		int nowy = bombs[i].first;
		int nowx = bombs[i].second;
		for (int d = 0; d < 4; d++) {
			for (int j = 1; j <= k; j++) {
				int ny = nowy + dir[0][d]*j;
				int nx = nowx + dir[1][d] * j;
				if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
				if (map[ny][nx] == '#')break;
				map[ny][nx] = '%';
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
			}
		cout << endl;
	}

}
