//https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

struct s {
	int i;
	char c;
	s(int num, char alpha) : i(num), c(alpha) {}
};


struct cmp_s {
	bool operator()(s a, s b) {

		if (a.i == b.i) {
			return a.c < b.c;
		}
		return a.i > b.i;
	}
};
int main() {

	int T;
	int a, b, c, d;
	int sum = 0;
	priority_queue<int, vector<int>, cmp> q;


	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < T - 1; i++) {
		b = q.top();
		q.pop();
		c = q.top();
		q.pop();
		d = b + c;
		q.push(d);
		sum += b + c;
	}


	cout << sum;
	return 0;
}
