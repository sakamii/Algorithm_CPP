#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10], ans[10];
bool visited[10];

void dfs(int m) {
	if (m == M) {
		for (int i = 0; i < m; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (visited[i]) continue;
		ans[m] = num[i];
		visited[i] = true;
		dfs(m + 1);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	sort(num, num + N);
	dfs(0);
	return 0;
}
