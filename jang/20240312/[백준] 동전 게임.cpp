#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int K, C;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> K >> C;
	for (int i = 0; i < C; i++) {
		int a, b;
		cin >> a >> b;

		int rest = K - max(a, b);
		//영희가 더 많이 이겼을 떄
		if (a > b && a - b - rest <= 2) {
			cout << "1" << '\n';
			continue;
		}
		//동수가 더 많이 이겼을 떄
		if (a < b && b - a - rest <= 1) {
			cout << "1" << '\n';
			continue;
			//예로 5라운드 2,4 이면
			//4-2-1<=1 가능 3,2일댸도 가능
		}
		if (a == b) cout << "1" << '\n';
		else cout << '0' << '\n';
	}

}
