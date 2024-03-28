/*
prefix sum 처럼 행과 열의 0번 인덱스에 계산할 값들을 더해 저장해둔다.
값의 입력마다 2차원 배열의 반복문을 돌지 않고,
입력이 끝나면 2중 for문으로 한 번에 처리한다.
값을 입력받을 때마다 배열을 갱신하면 당연히 시간초과 발생.
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m, q, a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		if (a == 1) v[b][0] += c;
		else v[0][b] += c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			v[i][j] += v[i][0] + v[0][j];
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}
}
