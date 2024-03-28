
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n, k, ans = 1e9, x, y, z;
vector<pii> dots[21];

void dfs(int color, int sx, int sy,int ex, int ey) {
	if (color == k + 1) {
		ans = min(ans, abs(ex - sx) * abs(ey - sy));
		return;
	}

	for (int i = 0; i < dots[color].size(); i++) {
		int x = dots[color][i].first, y = dots[color][i].second;
		int lx = min(sx, x), rx = max(ex, x);
		int ly = min(sy, y), ry = max(ey, y);
		if (ans <= abs(rx - lx) * abs(ry - ly)) continue;
		dfs(color + 1, lx, ly, rx, ry);
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		dots[z].push_back({ x,y });
	}

	dfs(1, 10000, 10000, -10000, -10000);

	cout << ans;
}
