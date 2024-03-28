#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int n, k;
	int arr[100001];
	int sum[100001] = { 0, };
	int max_s = -99999;
	int psum;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}

	max_s = sum[k];

	for (int i = 1; i <= n - k; i++) {
		psum = sum[k + i] - sum[i];
		max_s = max(max_s, psum);
	}
	
	cout << max_s;

	return 0;
}
