#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string st[31];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st[i];
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		int cnt = 0;
		int len = st[i].length();
		for (int j = 0; j < len / 2; j++) {
			if (st[i][j] != st[i][len - 1 - j]) {
				string st2 = st[i].substr(j, len - 2 * j); 
				string st3 = st2.substr(1, st2.length() - 1);
				string st4 = st2.substr(0, st2.length() - 1);
				flag = 1;
				if (cnt > 1) flag = 2;
				cnt++;
				for (int k = 0; k < st3.length() / 2; k++) {
					if (st3[k] != st3[st3.length() - 1 - k]) {
						flag1 = 2;
						st[i].erase(len - 1 - j, 1);
						break;
					}
				}
				for (int k = 0; k < st4.length() / 2; k++) {
					if (st4[k] != st4[st4.length() - 1 - k]) {
						st[i].erase(j, 1);
						flag2 = 2;
						break;
					}
				}
				if (flag1 == 2 && flag2 == 2) flag = 2;
			}
		}
		cout << flag << endl;
	}
}
