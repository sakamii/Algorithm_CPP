#include<iostream>
#include<vector>
using namespace std;


// 각 입력마다 출력이 하나씩 되는 경우
// cin.tie(0)와 "\n" 사용
// 2020KB, 24ms
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, C;

	cin >> K >> C;

	for (int i = 0; i < C; i++) {
		int m, n;
		cin >> m >> n;

		int ans = 0;

		// (m,n)이 가능한지 불가능한지 판단하기 위해
		// 이전 상태에서 가능했는지 불가능 했는지를 확인하는 방법 사용
		// 이전 상태에서 마지막으로 가능한 경우였다면 현재는 false;
		// m이 크냐 n이 크냐에 따라 경우가 달라지기 때문에 분리
		if (m > n) {
			int ago = m - 1;
			n++;
			if (ago - n > K - ago) ans = 0;
			else if (ago - n + 1 > K - ago) ans = 0;
			else ans = 1;
		}
		else if (m < n) {
			int ago = n - 1;
			if (ago - m > K - ago) ans = 0;
			else if (ago - m + 1 > K - ago) ans = 0;
			else ans = 1;
		}
		else ans = 1;


		cout << ans << "\n";

	}

	return 0;
}
