#include <iostream>
using namespace std;
int t, year, mon1, mon3, day, ans = 0;
int plan[13], min_sum[13] = { 0 };
void dfs(int now, int total) {
	if (now > 12) {
		if (ans > total) ans = total;
		return;
	}
	for (int i = now; i <= 12; i++) {
		if (plan[now] > 0) {
			now = i;
			break;
		}
	}
	dfs(now + 1, total + day * plan[now]);
	dfs(now + 1, total + mon1);
	dfs(now + 3, total + mon3);
}


int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> day >> mon1 >> mon3 >> year;
		for (int i = 1; i <= 12; i++) {
			int now;
			cin >> plan[i];
		}
		ans = year;
		dfs(0, 0);
		cout << "#" << tc << " " << ans<<endl;
	}
}
