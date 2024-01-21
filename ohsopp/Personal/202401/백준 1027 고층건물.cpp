
// https://www.acmicpc.net/problem/1027

#include <bits/stdc++.h>
using namespace std;

int n, i, j, b[55], c[55];
double mg, g;

int main() {
	cin >> n;

	for (i = 0; i < n; i++)
		cin >> b[i];

	for (i = 0; i < n; i++) {
		mg = -1e9;
		for (j = i + 1; j < n; j++) {
			g = (double)(b[j] - b[i]) / (j - i);
			if (mg < g) {
				mg = g;
				c[i]++; c[j]++;
			}
		}
	}

	cout << *max_element(c, c + n);
}
