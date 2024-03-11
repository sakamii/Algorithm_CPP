
/*
map으로 풀어보겠다고 고집을 부려서 여러사람 도움받아 얼렁뚱땅 푼 문제.

먼저 입력 받은 수들의 개수를 세서 map에 저장해준다.
(1) 현재 살펴보는 서로 다른 두 수가 모두 0이라면: 0의 개수가 2개보다 많다면 그 개수만큼 만들 수 있다.
(2) 하나만 0이라면: 0이 아닌 수의 개수가 1개보다 많다면 그 개수만큼 만들 수 있다.
(3) 둘 다 0이 아니고 서로 다른 수라면: 두 수의 합인 수의 개수만큼 만들 수 있다.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, res, v[2001];
map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!v[i] && !v[j] && m[0]) {    // (1)
				if (m[0] > 2) res += m[0];
				m[0] = 0;
			}
			else if (!v[i]) {    // (2)
				if (m[v[j]] > 1) {
					res += m[v[j]];
					m[v[j]] = 0;
				}
			}
			else if (!v[j]) {    // (2)
				if (m[v[i]] > 1) {
					res += m[v[i]];
					m[v[i]] = 0;
				}
			}
			else if (m[v[i] + v[j]]) {  // (3)
				res += m[v[i] + v[j]];
				m[v[i] + v[j]] = 0;
			}
		}
	}

	cout << res;
}
