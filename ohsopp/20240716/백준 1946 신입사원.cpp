#include <iostream>
#include <algorithm>

using namespace std;

int t, n, ans;
pair<int, int> v[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		ans = n;

		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;

		sort(v, v + n);
		int minScore = v[0].second;
		
		for (int i = 1; i < n; i++) {
			if (minScore < v[i].second)
				ans--;
			minScore = min(minScore, v[i].second);
		}

		cout << ans << '\n';
	}
}
