#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
int n, m, ans;
vector<string>v;

int main() {
	unordered_map<string, int>um;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		um[str] = 1;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (um[str] == 1) {
			ans++;
			v.push_back(str);
		}
	}
	cout << ans << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
