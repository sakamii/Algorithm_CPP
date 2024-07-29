#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long trees[1000002];

void bs() {
	long long s = 0, e = trees[N - 1], mid = 0;
	int ans = 0;
	while (s <= e) {
		mid = s + (e - s) / 2;
		long long sum = 0;
		for (int i = N - 1; i >= 0; --i) {
			if (trees[i] <= mid) break;
			sum += trees[i] - mid;
			if (sum >= M) break;
		}
		if (sum >= M) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> trees[i];
	}
	sort(trees, trees + N);
	bs();
	return 0;
}
