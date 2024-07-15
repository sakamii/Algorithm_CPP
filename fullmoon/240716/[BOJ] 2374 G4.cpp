#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	stack<unsigned long long> num;
	unsigned long long ans = 0;
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (num.empty()) {
			num.push(a);
		}
		else {
			if (a == num.top()) continue;
			if (a > num.top()) {
				ans += (a - num.top());
				num.pop();
				while (!num.empty() && num.top() <= a) {
					num.pop();
				}
			}
			num.push(a);
		}
	}
	while (num.size() > 1) {
		num.pop();
	}
	ans += (num.top() - a);
	cout << ans << "\n";
	return 0;
}
