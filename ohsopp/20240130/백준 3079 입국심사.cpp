
// https://www.acmicpc.net/problem/3079

#include <iostream>
using namespace std;

unsigned long long n, m, a[100001];
unsigned long long l = 1, k, mid, cnt, t, r;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		k = max(k, a[i]);
	}

	r = k * m;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += mid / a[i];

		if (cnt >= m) {
			r = mid - 1;
			t = mid;
		}
		else l = mid + 1;
	}

	cout << t;
}
