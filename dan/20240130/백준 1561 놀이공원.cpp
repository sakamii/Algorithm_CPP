#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, mid, t, l = 1, r = 60000000000;
vector<int>v;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	if (n <= m) {
		cout << n;
		return 0;
	}
	while (l <= r) {
		mid = (l + r) / 2;
		long long child = m;
		for (int i = 0; i < m; i++) {
			child += mid / v[i];
		}
		if (child >= n) {
			t = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	long long people = m;
	for (int i = 0; i < m; i++) {
		people += (t - 1) / v[i];
	}

	for (int i = 0; i < m; i++) {
		if (!(t % v[i])) people++;
		if (people == n) {
			cout << i + 1;
			return 0;
		}
	}
}
