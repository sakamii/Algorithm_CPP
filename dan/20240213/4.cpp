#include <iostream>
#include <vector>
using namespace std;
int t, n, ans, cnt = 0, maxs = 0;
int balloon[11] = { 0 }, visited[12] = { 0 };
void func() {
	if (cnt == n) {
		maxs = max(maxs, ans);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1)continue;
		int left = i - 1;
		int right = i + 1;
		while (left > 0 && visited[left] == 1) left--;
		while (visited[right] == 1) right++;
		if (left < 1 && right > n) ans += balloon[i];
		else if (left < 1) ans += balloon[right];
		else if (right > n)ans += balloon[left];
		else ans += balloon[left] * balloon[right];
		visited[i] = 1;
		cnt++;
		func();
		if (left < 1 && right > n) ans -= balloon[i];
		else if (left < 1) ans -= balloon[right];
		else if (right > n)ans -= balloon[left];
		else ans -= balloon[left] * balloon[right];
		visited[i] = 0;
		cnt--;
	}
}


int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		maxs = 0;
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			balloon[i] = a;
		}
		func();
		cout << "#" << tc + 1 << " " << maxs<<endl;
	}
}
