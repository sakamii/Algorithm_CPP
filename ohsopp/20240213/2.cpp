
// 지역구 나누기

#include <iostream>
#include <queue>
using namespace std;

int t, n, ans, total, v[10][10], p[10];
bool sel[10];

int bfs(bool g) {
	bool chk[10] = { 0 };
	int ret = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (sel[i] == g) {
			q.push(i);
			ret = 1;
			chk[i] = 1;
			break;
		}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
			if (sel[i] == g && !chk[i] && v[x][i]) {
				ret++;
				chk[i] = 1;
				q.push(i);
			}
	}
	return ret;
}

void dfs(int idx, int sum, int d, int k) {
	if (d == k) {
		int a = bfs(1);
		int b = bfs(0);
		if (a + b == n)
			ans = min(ans, abs(total - sum - sum));
		return;
	}

	for (int i = idx; i <= n; i++) {
		sel[i] = 1;
		dfs(i + 1, sum + p[i], d + 1, k);
		sel[i] = 0;
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		ans = 1e9;
		cin >> n;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> v[i][j];

		total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			total += p[i];
		}

		for (int i = 1; i < n; i++)
			dfs(1, 0, 0, i);

		cout << "#" << tc << " " << ans << endl;
	}
}
