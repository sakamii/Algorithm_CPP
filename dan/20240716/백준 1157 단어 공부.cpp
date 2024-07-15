#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;


int main() {
	int dat[50] = {0} , cnt = 0, ans = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] - 'a' >= 0 and str[i] - 'a' < 26) {
			dat[str[i] - 'a']++;
		}
		else {
			dat[str[i] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (dat[i] > 0 and dat[i] > cnt) {
			cnt = dat[i];
			ans = i;
		}
		else if (dat[i] > 0 and dat[i] == cnt) {
			ans = -1;
		}
	}
	if (ans == -1)
		cout << '?';
	else
		cout << char(ans + 'A');
}
