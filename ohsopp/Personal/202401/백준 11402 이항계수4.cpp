
// https://www.acmicpc.net/problem/11402
// 뤼카의 정리 - combination(n, r)을 m으로 나눈 나머지를 구할 때, n과 r을 m진수법으로 변환. 각 자릿수를 n1, n2,..(이하 n')와 r1, r2,..(이하 r')로 볼 때, (모든 combination(n', r?) % m을 곱한 값) % m이 구하는 값.

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll n, k, ans = 1, memo[2001][2001];
int m, idx;

// m진법으로 바꾸어 역순 저장하는 함수. ex) 45의 7진법은 63인데, getLuca(45, 7)은 역순인 [3, 6] 반환
vector<int> getLuca(ll val, int mod) {
	vector<int> ret;
	while (val) {
		ret.push_back(val % mod);
		val /= mod;
	}
	return ret;
}

ll comb(int n, int r) {
	if (n < r) return 0;
	if (n == r || !r) return 1;

	ll& ret = memo[n][r];
	if (ret) return ret;
	return ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % m;
}

int main() {
	cin >> n >> k >> m;

	vector<int> lcN, lcK;
	lcN = getLuca(n, m);
	lcK = getLuca(k, m);

	idx = min(lcN.size(), lcK.size());
	for (int i = 0; i < idx; i++, ans %= m)
		ans *= comb(lcN[i], lcK[i]);

	cout << ans;
}
