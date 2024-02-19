
#include <iostream>
using namespace std;

int t, a, b, c, d, m, dp[15];
int main(){
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> a >> b >> c >> d;
		for (int i = 3; i <= 14; i++) {
			cin >> m;
			dp[i] = min(dp[i - 1] + min(m * a, b), dp[i - 3] + c);
		}
    	cout << "#" << tc << " " << min(d, dp[14]) << '\n';
	}
}
