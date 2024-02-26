#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[1001], dp[1001], ans = 0;

int main() {
	int w = 0;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
