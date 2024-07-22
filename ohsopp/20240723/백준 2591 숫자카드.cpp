#include <iostream>
using namespace std;

string s;
long long dp[41] = { 1, 1 };
int n, l;

int main() {
	cin >> s;
	l = s.size();
	s = " " + s;
  s[1] -= '0';
  
	for (int i = 2; i <= l; i++) {
    s[i] -= '0';
		n = s[i - 1] * 10 + s[i];
		if (s[i]) dp[i] += dp[i - 1];
		if (n < 35 && s[i - 1]) dp[i] += dp[i - 2];
	}

	cout << dp[l];
}
