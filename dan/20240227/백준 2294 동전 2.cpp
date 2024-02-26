#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
	int dp[100001] = { 0 };
	int n, k, coin[1001];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	sort(coin, coin + n);
	for (int i = 1; i <= k; i++)dp[i] = 100001;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			int cnt = j / coin[i];
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == 100001) cout << -1;
	else cout << dp[k];
}
