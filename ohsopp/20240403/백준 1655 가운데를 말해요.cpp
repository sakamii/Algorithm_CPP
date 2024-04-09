
#include <iostream>
#include <queue>
using namespace std;

int n, k, mid;
priority_queue<int> l, r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> mid;
	cout << mid << '\n';

	for (int i = 2; i <= n; i++) {
		cin >> k;

		if (mid < k) r.push(-k);
		else l.push(k);

		if (i % 2 && l.size() < r.size()) {
			l.push(mid);
			mid = -r.top();
			r.pop();
		}
		else if (l.size() > r.size()) {
			r.push(-mid);
			mid = l.top();
			l.pop();
		}

		cout << mid << '\n';
	}
}
