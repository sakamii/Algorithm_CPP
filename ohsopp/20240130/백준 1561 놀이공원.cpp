
// https://www.acmicpc.net/problem/1561

#include <iostream>
#include <vector>
using namespace std;

long long n, m, mid, t, l = 1, r = 60000000000;
vector<int> v;

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		v.push_back(k);
	}

	if (n <= m) {
		cout << n;
		return 0;
	}

	while (l <= r) {		// 시간 기준으로 이분 탐색을 돌면서 정확히 n번째 사람이 놀이기구에 탑승할 때의 시각(t)를 구함
		mid = (l + r) / 2;

		long long c = m;	// 0초에 놀이기구 타러가는 사람 수 = 놀이기구 개수
		for (int i = 0; i < v.size(); i++)
			c += mid / v[i];

		if (c >= n) {
			r = mid - 1;
			t = mid;
		}
		else l = mid + 1;
	}

	// t-1초까지 탑승해있는 사람 수를 구하고
	long long child = m;
	for (int i = 0; i < v.size(); i++)
		child += (t - 1) / v[i];

	// 이후부터 놀이기구 운행시간과 t가 맞아 떨어질 때마다 한 명씩 탑승. 이때 1명씩 증가시키면서 n과 같아지면 종료
	for (int i = 0; i < v.size(); i++) {
		if (!(t % v[i])) child++;
		if (child == n) {
			cout << i + 1;
			return 0;
		}
	}
}
