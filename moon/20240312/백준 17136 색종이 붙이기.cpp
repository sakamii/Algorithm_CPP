#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[11][11];
int visited[11][11];
int cnt[5];
int total;
int ans, flag;
int sum;


// size 크기의 색종이를 붙일 수 있는지 확인
int check(int y, int x, int size) {

	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (!map[y + i][x + j] || visited[y + i][x + j]) return 0;
		}
	}

	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			visited[y + i][x + j] = 1;
			total--;
		}
	}

	return 1;
}


// 전체 size가 10x10이기 때문에 완전탐색
void dfs(int level) {

	// 이미 사용한 종이의 수가 ans보다 크면 더 해볼 필요 x
	if (sum > ans) return;
	// 이전에 사용한 종이의 갯수가 5장보다 많다면 back
	if (cnt[level] < 0) return;
	// 모든 1이 색종이로 채워진 경우
	if (total == 0) {
		flag = 1;
		ans = min(ans, sum);
		return;
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (!map[i][j] || visited[i][j]) continue;
			for (int k = 4; k >= 0; k--) {
				if (!check(i, j, k)) continue;
				cnt[k]--;
				sum++;
				dfs(k);
				//복구
				sum--;
				cnt[k]++;
				for (int ii = 0; ii <= k; ii++) {
					for (int jj = 0; jj <= k; jj++) {
						visited[i + ii][j + jj] = 0;
						total++;
					}
				}
			}
			// 색종이를 붙이면 더이상 해당 좌표 탐색 x
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ans = 21e8;

	for (int i = 0; i < 5; i++) {
		cnt[i] = 5;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j]) total++;
		}
	}

	if (!total) {
		cout << 0;
		return 0;
	}

	dfs(0);

	if (!flag) cout << -1;
	else cout << ans;

	return 0;
}
