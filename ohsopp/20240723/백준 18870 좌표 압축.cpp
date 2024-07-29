#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, v[1000001];
map<int, int> m;
vector<int> a;

int lower_bs(int s, int e, int tar) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] < tar) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]] = 1;
	}

	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		a.push_back(it->first);

	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++)
		cout << lower_bs(0, a.size() - 1, v[i]) << " ";
}
