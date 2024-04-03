#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool visited[1001];
vector<vector<int>>arr;
int weight[1001][1001];

void DFS(int a, int b, int tempSum) {
	if (a == b) {
		cout << tempSum << '\n';
		return;
	}
	for (int i = 0; i < arr[a].size(); i++) {
		if (!visited[arr[a][i]]) {
			visited[arr[a][i]] = true;
			DFS(arr[a][i], b, tempSum + weight[a][arr[a][i]]);
			visited[arr[a][i]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	arr.resize(N + 1);
	int a, b, c;

	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		arr[a].push_back(b);
		arr[b].push_back(a);
		weight[a][b] = c;
		weight[b][a] = c;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		visited[a] = true;
		DFS(a, b, 0);
		visited[a] = false;
	}

}
