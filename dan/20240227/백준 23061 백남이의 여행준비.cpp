#include <iostream>
#include <algorithm>
using namespace std;
int n, m, maxk = 0, w[110], v[110], sack[110], ans = 1;
int dp[110][1000001] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> sack[i];
		maxk = max(sack[i], maxk);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= maxk; j++) {
			// 만약 i 번째 물건을 넣을 수 있다면
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int i = 2; i <= m; i++) {
		if (dp[n][sack[ans]] * sack[i] < dp[n][sack[i]] * sack[ans]) {
			ans = i;
		}
	}
	cout << ans;
}
