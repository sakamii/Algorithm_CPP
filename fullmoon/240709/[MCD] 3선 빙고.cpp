#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pair<int, int> pos[26] = { {0, 0} };
	for (int i = 0; i < 5; i++) {
		int num;
		for (int j = 0; j < 5; j++) {
			cin >> num;
			pos[num] = { i, j };
		}
	}

	int row[5] = { 0, }, col[5] = { 0, }, diag[2] = { 0, };
	int cnt = 0, ans = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		for (int j = 0; j < 5; j++) {
			cin >> num;
			if (ans > 0) continue;
			int r = pos[num].first, c = pos[num].second;
			row[r]++;
			col[c]++;
			if (r == c) diag[0]++;
			if (r + c == 4) diag[1]++;
			if (row[r] == 5) {
				row[r] = 0;
				cnt++;
			}
			if (col[c] == 5) {
				col[c] = 0;
				cnt++;
			}
			if (diag[0] == 5) {
				diag[0] = 0;
				cnt++;
			}
			if (diag[1] == 5) {
				diag[1] = 0;
				cnt++;
			}
			if (cnt == 3) ans = num;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
