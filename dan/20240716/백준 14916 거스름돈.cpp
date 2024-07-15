#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;


int main() {
	int n, ans = -1;
	cin >> n;
	for (int i = n / 5; i >= 0; i--) {
		int now = n - i * 5;
		if (now % 2 != 0)continue;
		ans = i + now / 2;
		break;
	}
	if (ans == -1)
		cout << -1;
	else
		cout << ans;
}
