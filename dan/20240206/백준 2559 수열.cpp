#include <iostream>
using namespace std;
int n, k;
int num[100001];
int max_num = -99999;
int prefixsum[100002] = { 0 };
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		prefixsum[i+1] = prefixsum[i] + num[i];
	}
	for (int i = 0; i < (n - k + 1); i++) {
		int now = 0;
		now = prefixsum[i + k] - prefixsum[i];
		if (max_num < now) max_num = now;
	}
	cout << max_num;
}
