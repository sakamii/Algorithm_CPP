#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int num[1002] = { 0, };
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
	}
	int dp[1002] = { 0, };
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (num[i] < num[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
				ans = max(ans, dp[j]);
			}
		}
	}
	cout << ans + 1 << "\n";
	return 0;
}
