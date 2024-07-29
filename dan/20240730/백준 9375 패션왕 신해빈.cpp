#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int t, n;

int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int ans = 1;
		unordered_map<string, int>um;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string st1, st2;
			cin >> st1 >> st2;
			um[st2]++;
		}
		// 의상의 종류 개수를 알아내야함 
		for (auto iter = um.begin(); iter != um.end(); iter++) {
			ans *= (iter->second) + 1;
		}
		cout << ans - 1<< endl;
	}
}
