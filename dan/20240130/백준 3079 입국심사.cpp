#include <iostream>
#include <algorithm>
using namespace std;
int m, n;
long long max_value = 0, t[100001], result=0;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		max_value = max(max_value, t[i]);
	}
	long long left = 0, right = max_value * m, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		long double mt = 0;
		for (int i = 0; i < n; i++) {
			mt += (mid / t[i]);
		}
		if (mt >= m) {
			right = mid - 1;
			result = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result;
}
