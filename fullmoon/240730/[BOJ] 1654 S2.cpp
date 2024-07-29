#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
long long line[10002];

bool getCount(int num) {
	int cnt = 0;
	for (int i = 0; i < K; ++i) {
		cnt += line[i] / num;
	}
	if (cnt >= N) return true;
	return false;
}

void bs() {
	long long s = 1, e = line[K - 1], mid = 0;
	long long ans = 0;
	while (s <= e) {
		mid = s + (e - s) / 2;
		if (getCount(mid)) {
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
	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> line[i];
	}
	sort(line, line + K);
	bs();
	return 0;
}
