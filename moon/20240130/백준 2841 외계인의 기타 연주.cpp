#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, p,k;
	stack<int> s[7];
	int a;
	int count = 0;

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> p;
		while (1) {
			if (s[a].empty() == 1) {
				s[a].push(p);
				count++;
				break;
			}
			else if (p > s[a].top()) {
				s[a].push(p);
				count++;
				break;
			}
			else if (p == s[a].top()) break;
			else if (p < s[a].top()) {
				s[a].pop();
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
