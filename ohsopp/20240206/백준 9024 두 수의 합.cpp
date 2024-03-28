
// https://www.acmicpc.net/problem/9024

#include <iostream>
#include <algorithm>
using namespace std;

int t, n, k, l, diff, ans, r, v[1000001];

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++)
            scanf("%d", v + i);

		sort(v, v + n);

		diff = 1e9;
		ans = 0;
		l = 0, r = n - 1;
		while (l < r) {
			int sum = v[l] + v[r];

			if (abs(sum - k) < abs(diff - k)) {
				diff = sum;
				ans = 1;
			}
			else if (abs(sum - k) == abs(diff - k))
				ans++;

			if (sum > k) r--;
			else l++;
		}
		cout << ans << '\n';
	}
}
