#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], dp[1001];
int ans;

int main() {
	// 지금 들어온거 이전 확인해서 +1
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
				ans = max(dp[i], ans);
			}
		}
	}
	cout << ans + 1;
}
