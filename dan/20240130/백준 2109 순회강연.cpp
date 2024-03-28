#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int, int> pint;
vector<pint> pay(10001);
int n, d, p, salary = 0, maxdate = 0;
int dat[10001] = { 0 };

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p >> d;
		if (d > maxdate) maxdate = d;
		pay[i] = make_pair(p, d);
	}
	sort(pay.begin() + 1, pay.end(), [](pint a, pint b) {return a.first > b.first; });
	int de = -1;
	while (maxdate > 0) {
		for (int i = 1; i <= n; i++) {
			if (dat[i] == 1) continue;
			else if (pay[i].second >= maxdate) {
				salary += pay[i].first;
				dat[i] = 1;
				break;
			}
		}
		maxdate--;
	}
	cout << salary;
}
