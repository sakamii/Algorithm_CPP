#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		vector<int>v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		int l = 0, r = n - 1;
		int result = 1e9, cnt = 0;
		while (l < r) {
			int sum = v[l] + v[r];
			if (abs(sum - k) < abs(result-k)) {
				cnt = 1;
				result = sum;
			}
			else if (abs(sum - k) == abs(result-k)) {
				cnt++;
			}
			if (sum > k) r--;
			else l++;
		}
		cout << cnt << endl;
	}
	return 0;
}
