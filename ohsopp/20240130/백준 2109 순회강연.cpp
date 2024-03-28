
// https://www.acmicpc.net/problem/2109

#include <iostream>
#include <queue>
using namespace std;

int n, p, d, ans;
priority_queue<pair<int, int>> pq;
bool v[10001];

int main() {
	cin >> n;

	while (n--) {
		cin >> p >> d;
		pq.push({ p,d });  // {비용, 요청기한}
	}

	while (!pq.empty()) {
		p = pq.top().first;
		d = pq.top().second;
		pq.pop();

		for (int i = d; i; i--)
			if (!v[i]) {
				v[i] = 1;
				ans += p;
				break;
			}
	}
	cout << ans;
}
