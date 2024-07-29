#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
	fastio;
	while (true) {
		long long m = 0, n = 0;
		long long ans = 0;
		unordered_map<long long, int>um;
		cin >> m >> n;
		if (m == 0 and n == 0) return 0;
		for (int i = 0; i < m; i++) {
			long long a;
			cin >> a;
			um[a]++;
		}
		for (int i = 0; i < n; i++) {
			long long a; cin >> a;
			if (um[a])ans++;
		}

		cout << ans << '\n';
	}
}#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
	fastio;
	while (true) {
		long long m = 0, n = 0;
		long long ans = 0;
		unordered_map<long long, int>um;
		cin >> m >> n;
		if (m == 0 and n == 0) return 0;
		for (int i = 0; i < m; i++) {
			long long a;
			cin >> a;
			um[a]++;
		}
		for (int i = 0; i < n; i++) {
			long long a; cin >> a;
			if (um[a])ans++;
		}

		cout << ans << '\n';
	}
}
