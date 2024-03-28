
// https://www.acmicpc.net/problem/2841

#include <iostream>
#include <queue>
using namespace std;

int  n, p, a, b, flag, ans;
priority_queue<int> q[500001];

int main() {
	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		flag = 1;
		ans++;
		while (!q[a].empty() && q[a].top() >= b) {
			if (q[a].top() == b) {
				ans--;
				flag = 0;
				break;
			}
			ans++;
			q[a].pop();
		}

		if (flag)
			q[a].push(b);
	}
	cout << ans;
}
