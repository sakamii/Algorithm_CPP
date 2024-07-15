#include <iostream>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
queue<pair<int,int>>q;
int t, n, m, val = 0, cnt = 0;

int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			val = max(a, val);
			q.push({ a,i });
		}
		while (!q.empty()) {
			int nv = q.front().first;
			int ord = q.front().second;
			q.pop();
			if (nv < val) {
				// 뒤로 보내기
				q.push({ nv, ord });
			}
			else {
				cnt++;
				if (ord == m) {
					cout << cnt << '\n';
				}
				val = 0;
				for (int i = 0; i < q.size(); i++) {
					val = max(val, q.front().first);
					q.push({ q.front().first, q.front().second });
					q.pop();
				}
			}
		}
		cnt = 0;
		val = 0;
	}
}
