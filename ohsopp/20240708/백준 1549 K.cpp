
#include <iostream>
using namespace std;

long long n, v[3005];
int k, ans = 1e9;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}

	for (int i = 1; i <= n / 2; i++)
		for (int j = i; j <= n; j++)
			for (int l = j + i; l <= n; l++) {
				long long r = abs((v[j] - v[j - i]) - (v[l] - v[l - i]));
				if (r <= ans) {
					ans = r;
					k = i;
				}
			}

	cout << k << endl << ans;
}
