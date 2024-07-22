#include <iostream>
#include <algorithm>

using namespace std;
int dp[5001][3];
int n, ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + b;
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + c;
	}
	ans = min(dp[n][0], dp[n][1]);
	ans = min(dp[n][2], ans);
	cout << ans;
}
