
#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool vis[100001];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ n,0 });
	vis[n] = 1;

	while (!q.empty()) {
		int x = q.front().first, c = q.front().second;
		q.pop();

		if (x == k) {
			cout << c;
			return;
		}

		if (2 * x <= 100000 && !vis[2 * x]) {
			vis[2 * x] = 1;
			q.push({ 2 * x, c });
		}
		if (x - 1 >= 0 && !vis[x - 1]) {
			vis[x - 1] = 1;
			q.push({ x - 1,c + 1 });
		}
		if (x + 1 <= 100000 && !vis[x + 1]) {
			vis[x + 1] = 1;
			q.push({ x + 1,c + 1 });
		}
		
	}
}

int main() {
	cin >> n >> k;
	bfs();
}
