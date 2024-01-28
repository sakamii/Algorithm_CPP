#include <iostream>
#include <stack>
using namespace std;

int main() {

	int n, p, k, a;
	int count = 0;

	// stack 크기 할당에서 runtime error 조심
	stack<int> s[7];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a >> p;
		while (1) {
			if (s[a].empty()) {
				s[a].push(p);
				count++;
				break;
			}
			else if (p > s[a].top()) {
				s[a].push(p);
				count++;
				break;
			}
			else if (p < s[a].top()) {
				s[a].pop();
				count++;
			}
			else if (p == s[a].top()) break;
		}
	}

	cout << count;

	return 0;
}
