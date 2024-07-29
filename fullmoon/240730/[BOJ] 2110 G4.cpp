#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int house[200002];
int distHouse[200002];

bool canWifi(int mid) {
	int dist = 0, cnt = 0;
	for (int i = 0; i < N - 1; ++i) {
		dist += distHouse[i];
		if (dist >= mid) {
			dist = 0;
			cnt++;
		}
		if (cnt >= C - 1) return true;
	}
	return false;
}

void bs() {
	long long s = 1, e = house[N - 1] - house[0];
	int mid = 0, ans = 0;
	while (s <= e) {
		mid = s + (e - s) / 2;
		if (canWifi(mid)) {
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
	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		cin >> house[i];
	}
	sort(house, house + N);
	for (int i = 0; i < N - 1; ++i) {
		distHouse[i] = house[i + 1] - house[i];
	}
	bs();
	return 0;
}
