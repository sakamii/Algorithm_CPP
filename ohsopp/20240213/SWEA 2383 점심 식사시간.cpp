
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y;
}person;

typedef struct {
	int x, y, h;
}stairs;

int t, n, ans, seq[11], arr[11][11];
vector<person> v;
vector<stairs> vs;

int getDist(person p, stairs s) {
	return abs(p.x - s.x) + abs(p.y - s.y);
}

int calc() {
	int r1 = 0, r2 = 0, ret1[3] = { 0 }, ret2[3] = { 0 };

	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < v.size(); i++) {
		if (seq[i] == 1)
			v1.push_back(getDist(v[i], vs[0]));
		else
			v2.push_back(getDist(v[i], vs[1]));
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int i = 0;
	for (; i < v1.size(); i++)
		ret1[i % 3] = max(ret1[i % 3], v1[i] + 1) + vs[0].h;
	r1 = max(ret1[0], max(ret1[1], ret1[2]));

	i = 0;
	for (; i < v2.size(); i++)
		ret2[i % 3] = max(ret2[i % 3], v2[i] + 1) + vs[1].h;
	r2 = max(ret2[0], max(ret2[1], ret2[2]));

	return max(r1, r2);
}

void dfs(int d) {
	if (d == v.size()) {
		ans = min(ans, calc());
		return;
	}

	for (int i = 1; i <= 2; i++) {
		seq[d] = i;
		dfs(d + 1);
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n;

		v.clear(); vs.clear();

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) v.push_back({ i,j });
				if (arr[i][j] > 1) vs.push_back({ i,j,arr[i][j] });
			}

		ans = 1e9;
		dfs(0);

		cout << "#" << tc << " " << ans << endl;
	}
}
