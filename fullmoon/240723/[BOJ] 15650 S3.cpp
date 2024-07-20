#include <iostream>
using namespace std;

int N, M;
int arr[10];

void dfs(int n, int m) {
	if (m == M) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = n; i <= N; i++) {
		arr[m] = i;
		dfs(i + 1, m + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}
