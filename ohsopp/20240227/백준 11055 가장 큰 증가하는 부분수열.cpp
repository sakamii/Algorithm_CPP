
#include <iostream>
using namespace std;

int n, ma, a[1001], d[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
		for (int j = 0; j < i; j++)
			if (a[j] < a[i]) d[i] = max(d[i], d[j] + a[i]);
    }

	for (auto k : d) ma = max(ma, k);
	cout << ma;
}
