#include <iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// 빙고의 개수, 마지막 숫자
	int cnt = 0, flag = 0;
	int dir[2][8] = { {-1,1,0,0,-1,1,1,-1},{0,0,-1,1,-1,1,-1,1} };
	int bingo[5][5][2] = { 0, };
	vector<pair<int, int>>loc[26];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> bingo[i][j][0];
			loc[bingo[i][j][0]].push_back({ i,j });
		}
	}
	for (int i = 0; i < 5; i++) {
		if (flag)break;
		for (int j = 0; j < 5; j++) {
			int n;
			cin >> n;
			int ny = loc[n][0].first;
			int nx = loc[n][0].second;
			bingo[ny][nx][1] = 1;
			// 상하좌우로 살피며 빙고 완성됐는지 확인
			// 열 연결된 개수, 행 연결된 개수
			int ccnt = 1, rcnt = 1, lcnt=1, rrcnt=1;
			for (int i = 0; i < 2; i++) {
				int k = 1;
				while (true) {
					int nowy = ny + dir[0][i] * k;
					int nowx = nx + dir[1][i] * k;
					if (nowy < 0 || nowy >= 5 || nowx < 0 || nowx >= 5)break;
					if (bingo[nowy][nowx][1])ccnt++;
					else break;
					k++;
				}
			}
			for (int i = 2; i < 4; i++) {
				int k = 1;
				while (true) {
					int nowy = ny + dir[0][i] * k;
					int nowx = nx + dir[1][i] * k;
					if (nowy < 0 || nowy >= 5 || nowx < 0 || nowx >= 5)break;
					if (bingo[nowy][nowx][1])rcnt++;
					else break;
					k++;
				}
			}
			for (int i = 4; i < 6; i++) {
				int k = 1;
				while (true) {
					int nowy = ny + dir[0][i] * k;
					int nowx = nx + dir[1][i] * k;
					if (nowy < 0 || nowy >= 5 || nowx < 0 || nowx >= 5)break;
					if (bingo[nowy][nowx][1])lcnt++;
					else break;
					k++;
				}
			}
			for (int i = 6; i < 8; i++) {
				int k = 1;
				while (true) {
					int nowy = ny + dir[0][i] * k;
					int nowx = nx + dir[1][i] * k;
					if (nowy < 0 || nowy >= 5 || nowx < 0 || nowx >= 5)break;
					if (bingo[nowy][nowx][1])rrcnt++;
					else break;
					k++;
				}
			}
			int de33 = -1;
			if (rcnt == 5)cnt++;
			if (ccnt == 5)cnt++;
			if (lcnt == 5)cnt++;
			if (rrcnt == 5)cnt++;
			if (cnt >= 3) {
				cout << n;
				flag = 1;
				break;
			}
		}
	}
}
