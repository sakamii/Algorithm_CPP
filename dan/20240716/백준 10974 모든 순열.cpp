#include <iostream>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, m;
vector<int>nn;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		nn.push_back(i);
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << nn[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(nn.begin(), nn.end()));

}
