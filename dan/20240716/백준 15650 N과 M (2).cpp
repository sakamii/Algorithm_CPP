#include <iostream>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, m;
int dat[10];

void comb(int now, int fc) {
	if (fc == m) {
		for (int i = 1; i <= n; i++) {
			if (dat[i] == 1)cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = now; i <= n; i++) {
		dat[i] = 1;
		comb(i+1, fc+1);
		dat[i] = 0;
	}
}


int main() {
	cin >> n >> m;
	comb(1, 0);
}
