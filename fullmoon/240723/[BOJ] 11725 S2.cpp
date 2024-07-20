#include <iostream>
#include <queue>
using namespace std;

queue<int> nodes[100002];
int parents[100002];

void findParents(int n) {
	while (!nodes[n].empty()) {
		int now = nodes[n].front();
		nodes[n].pop();
		if (parents[now]) continue;
		parents[now] = n;
		findParents(now);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].push(b);
		nodes[b].push(a);
	}
	parents[1] = 1;
	findParents(1);
	for (int i = 2; i <= N; i++) {
		cout << parents[i] << "\n";
	}
	return 0;
}
