#include <iostream>
#include<climits>
using namespace std;

int main() {
	long long arr[100001] = { 0 }, diff=0;
	int n, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int dif = arr[i] - arr[i - 1];
		if (i > 0 and dif > 0) {
			if (diff < dif) {
				ans = i + 1;
				diff = dif;
			}
		}
	}
	if (!ans)cout << 0;
	else cout << ans - 1 << " " << ans;
}
