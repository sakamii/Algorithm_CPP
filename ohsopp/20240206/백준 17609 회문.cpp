
// https://www.acmicpc.net/problem/17609

#include <iostream>
using namespace std;

int n;
string s;

int dfs(int l, int r, int c, bool flag) {
	if (l > r) return min(c, 2);

	int ret = 2;
	if (s[l] == s[r]) 
		return dfs(l + 1, r - 1, c, flag);
	else {
		if (!flag) {
				ret = dfs(l + 1, r, c + 1, 1);
				ret = min(ret, dfs(l, r - 1, c + 1, 1));
		}
		else ret = 2;
		return ret;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << dfs(0, s.size() - 1, 0, 0) << endl;
	}
}
