#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, t[100001], max_value = 0;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		max_value = max(max_value, t[i]);
	}
	int left = 0, right = max_value * m, mid=0;
	while (left <= right) {
		mid = (left + right) / 2;
		int mt = 0;
		for (int i = 0; i < n; i++) {
			mt += mid / t[i];
		}
		if (mt > m) {
			right = mid - 1;
		}
		else if(mt < m) {
			left = mid + 1;
		}
		else {
			break;
		}
	}
	cout << mid;
}
