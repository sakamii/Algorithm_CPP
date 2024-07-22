#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
int n, m, ans;
vector<string>v;


int main() {
	cin >> n;
	ans = n;
	string str;
	for (int i = 0; i < n; i++) {
		unordered_map<char, int>um;
		cin >> str;
		um[str[0]] = 1;
		for (int j = 1; j < str.length(); j++) {
			if (str[j - 1] != str[j] && um[str[j]] == 1) {
				ans--;
				break;
			}
			um[str[j]] = 1;
		}
	}
	cout << ans;
}
