#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> item[102];
int bag[102][100002];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		int W, V;
		cin >> W >> V;
		item[i] = { W, V };
	}
	sort(item, item + N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			int w = item[i].first, v = item[i].second;
			if (j < w) {
				bag[i][j] = bag[i - 1][j];
			}
			else {
				bag[i][j] = max(v + bag[i - 1][j - w], bag[i - 1][j]);
			}
		}
	}
	cout << bag[N][K] << "\n";
	return 0;
}
