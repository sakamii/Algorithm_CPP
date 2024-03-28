//https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>
using namespace std;


int main() {

	int a=0;
	int n;

	queue <int> q;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		if (q.size() == 1) {
			a = q.front();
			break;
		}
		q.pop();
		if (q.size() == 1) {
			a = q.front();
			break;
		}
		q.push(q.front());
		q.pop();
	}

	cout << a;



	return 0;
}
