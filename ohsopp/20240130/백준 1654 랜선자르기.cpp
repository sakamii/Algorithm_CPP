
// https://www.acmicpc.net/problem/1654

#include <iostream>
using namespace std;

int k, n, cnt, arr[1000001];
long long l = 1, mid, r = 2147483647;

int main() {
	cin >> k >> n;

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	// 랜선 길이를 기준으로 이분탐색
	while (l <= r) {
		mid = (l + r) / 2;

		cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += arr[i] / mid;

		// 최대 랜선의 길이를 구하므로 등호를 mid가 늘어나는 조건문에 넣음
		if (cnt < n) r = mid - 1;
		else l = mid + 1;
	}
	cout << r;
}
