#include <iostream>

using namespace std;
long long n, m;

int main() {
	cin >> n >> m;
	int z = (m * 100) / n;
	if (z >= 99) {
		cout << -1;
		return 0;
	}
	int left = 0;
	long long right = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int now = ((m + mid) * 100) / (n + mid);

		if (z < now) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;

}
