#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int hi = 0, pre, cur, ans = 0;
	cin >> pre;
	for (int i = 2; i <= N; i++) {
		cin >> cur;
		if (cur - pre > hi) {
			hi = cur - pre;
			ans = i;
		}
		pre = cur;
	}
	if (ans == 0) {
		cout << 0 << "\n";
	}
	else {
		cout << ans - 1 << " " << ans << "\n";
	}

	return 0;
}
