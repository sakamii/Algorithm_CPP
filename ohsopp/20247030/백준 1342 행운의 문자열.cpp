
#include <iostream>
using namespace std;

string s;
int ans, alp[26];
bool vis[11];

bool lucky(string str) {
	for (int i = 0; i < str.size() - 1; i++)
		if (str[i] == str[i + 1]) return false;
	return true;
}

void dfs(int d, string str) {
	if (d == s.size()) {
		if (lucky(str)) ans++;
		return;
	}

	for (int i = 0; i < s.size(); i++)
		if (!vis[i]) {
			vis[i] = 1;
			dfs(d + 1, str + s[i]);
			vis[i] = 0;
		}

}

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		alp[s[i] - 'a']++;

	dfs(0, "");

	for (int i = 0; i < 26; i++) {
		if (alp[i] <= 1) continue;
		for (int j = 1; j <= alp[i]; j++)
			ans /= j;
	}

	cout << ans;
}
