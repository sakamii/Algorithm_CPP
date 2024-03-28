
// 전구 켜기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, x, s, NUM, light[11];
bool vis[1030];
vector<int> v[11];

void bfs() {
	queue<pair<int, int>> q;
	vis[s] = 0;
	q.push({ s, 0 });

	while (!q.empty()) {
		int cur = q.front().first, c = q.front().second;
		q.pop();

		if (cur == NUM) {
			cout << c;
			return;
		}

		for (int i = 1; i <= m; i++) {
			int next = cur;
			for (int j = 0; j < v[i].size(); j++) {
				int x = v[i][j];	// i번째 스위치에 연결된 전구
				next ^= 1 << (n - x);
			}

			if (!vis[next]) {
				vis[next] = 1;
				q.push({ next, c + 1 });
			}
		}
	}
	cout << -1;
}

int main() {
	cin >> n >> m >> k;
	NUM = (1 << n) - 1;

	for (int i = 1; i <= n; i++) {
		cin >> light[i];
		s += light[i] << (n - i);
	}

	for (int i = 1; i <= m; i++)
		for (int j = 0; j < k; j++) {
			cin >> x;
			v[i].push_back(x);
		}

	bfs();
}
