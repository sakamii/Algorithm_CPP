#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int na, nb;
	cin >> na >> nb;
	map<int, bool> a;
	for (int i = 0; i < na; i++) {
		int num;
		cin >> num;
		a.insert({ num, 1 });
	}
	for (int i = 0; i < nb; i++) {
		int num;
		cin >> num;
		if (a.find(num) != a.end()) {
			a.erase(num);
		}
	}
	cout << a.size() << "\n";
	for (auto iter : a) {
		cout << iter.first << " ";
	}
	return 0;
}
