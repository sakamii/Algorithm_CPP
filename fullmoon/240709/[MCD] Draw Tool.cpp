#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	int map[12][12] = { 0, };
	int color, y1, x1, y2, x2;
	for (int i = 0; i < Q; i++) {
		cin >> color >> y1 >> x1 >> y2 >> x2;
		if (y1 <= y2 && x1 <= x2) {
			for (int y = y1; y <= y2; y++) {
				for (int x = x1; x <= x2; x++) {
					map[y][x] = max(map[y][x], color);
				}
			}
		}
		else if (y1 <= y2 && x1 > x2) {
			for (int y = y1; y <= y2; y++) {
				for (int x = x2; x <= x1; x++) {
					map[y][x] = max(map[y][x], color);
				}
			}
		}
		else if (y1 > y2 && x1 <= x2) {
			for (int y = y2; y <= y1; y++) {
				for (int x = x1; x <= x2; x++) {
					map[y][x] = max(map[y][x], color);
				}
			}
		}
		else {
			for (int y = y2; y <= y1; y++) {
				for (int x = x2; x <= x1; x++) {
					map[y][x] = max(map[y][x], color);
				}
			}
		}
	}

	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!map[y][x]) continue;
			for (int i = 1; i <= N; i++) {
				int cnt = 0;
				for (int r = y; r < y + i; r++) {
					for (int c = x; c < x + i; c++) {
						if (map[y][x] == map[r][c]) {
							cnt++;
						}
						else break;
					}
					if (cnt < i) break;
				}
				if (cnt == i * i) ans = max(ans, cnt);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
