#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs[1002][1002];

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	cout << lcs[str1.size()][str2.size()] << "\n";
	return 0;
}
