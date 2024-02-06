#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001] = { 0 };

int main() {
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		int min_value = 1000001, cnt=0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + n);
		int de = -1;
		int l = 0, r = n - 1;
		while (arr[l] < arr[r]) {
			int sum = arr[l] + arr[r];
			if (abs(sum-k) == min_value) {
				cnt++;
			}
			else if (abs(sum-k) < min_value) {
				cnt = 1;
				min_value = abs(sum - k);
			}
			if (sum >= k) {
				r--;
			}
			else if (sum < k) {
				l++;
			}
		}
		cout << cnt << endl;
	}
}
