#include <iostream>
#include <vector>
using namespace std;
int n, m, k, minc=60000000, cnt=0;
vector<vector<int>>links;
int bulb[101], visited[101];

void find() {
	for (int i = 1; i <= n; i++) {
		if (bulb[i] == 0) break;
		if(i==n) minc = min(minc, cnt);
	}
	for (int i = 0; i < m; i++) {
		if (visited[i] == 1) continue;
		for (int j = 0; j < links[i].size(); j++) {
			int now = links[i][j];
			bulb[now] = bulb[now] == 1 ? 0 : 1;
		}
		visited[i] = 1;
		cnt++;
		find();
		for (int j = 0; j < links[i].size(); j++) {
			int now = links[i][j];
			bulb[now] = bulb[now] == 1 ? 0 : 1;
		}
		visited[i] = 0;
		cnt--;
	}
}

int main() {
	cin >> n >> m >> k;
	links.resize(m);
	for (int i = 0; i < n; i++) cin >> bulb[i+1];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++) {
			int light;
			cin >> light;
			links[i].push_back(light);
		}
	int de = -1;
	find();
	cout << minc;
}
