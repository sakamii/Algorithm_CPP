
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, c, x, y;
vector<pair<int, int>> v[1005];
int dist[1005];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,x });

	for (int i = 0; i <= 1000; i++)
		dist[i] = 1e9;
	dist[x] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second, d = pq.top().first;
		pq.pop();

		if (dist[cur] < d) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nd = d + v[cur][i].second;

			if (dist[next] > nd) {
				dist[next] = nd;
				pq.push({ nd,next });
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	cin >> x >> y;
	dijkstra();
	cout << dist[y];
}
