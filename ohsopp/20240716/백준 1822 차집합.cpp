#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int na, nb, k;
map<int, int> m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> na >> nb;

	for (int i = 0; i < na; i++) {
		cin >> k;
		m[k] = 1;
	}

	for (int i = 0; i < nb; i++) {
		cin >> k;
		if (m[k]) m[k] = 2;
	}

	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
		if (it->second == 1) v.push_back(it->first);

	cout << v.size() << '\n';
  
	if (v.size())
		for (auto r : v)
			cout << r << " ";
}
