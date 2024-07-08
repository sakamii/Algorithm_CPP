#include <iostream>
#include <algorithm>
using namespace std;

int price[100002];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	sort(price, price + N);
	
	long long ans = 0, ans_price = 0, pre = 0;
	for (int i = 0; i < N; i++) {
		if (pre == price[i]) continue;
		long long profit = (long long)price[i] * (long long)(N - i);
		if (profit > ans) {
			ans = profit;
			ans_price = price[i];
		}
		pre = price[i];
	}
	cout << ans << " " << ans_price << "\n";

	return 0;
}
