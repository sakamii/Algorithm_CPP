#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<int> s[7];
	int n, p, now, prt, cnt = 0;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> now >> prt;
		if (!s[now].empty() && s[now].top() > prt) {
			while (!s[now].empty() && s[now].top() > prt) {
				s[now].pop();
				cnt++;
			}
		}
		if (s[now].empty() || s[now].top() < prt) {
			s[now].push(prt);
			cnt++;
		}
	}
	cout << cnt;
}
