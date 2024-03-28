/*
유니온 파인드의 집합 개수를 구하는 것처럼 진행.
1일 때 집합 개수를 1 증가시키고, 좌우를 살펴서 집합이면 집합 개수 1씩 빼주기.
*/

#include <iostream>
using namespace std;

int n, m, k, r, cnt;
bool v[1000003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i]) {
			cnt++;
			if (v[i - 1]) cnt--;
			if (v[i + 1]) cnt--;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> k;

		if (!k) cout << cnt << '\n';
		else {
			cin >> r;
			if (v[r]) continue;
			else {
				v[r] = 1;
				cnt++;
				if (v[r - 1]) cnt--;
				if (v[r + 1]) cnt--;
			}
		}
	}
}
