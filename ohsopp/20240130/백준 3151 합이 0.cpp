
// https://www.acmicpc.net/problem/3151

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, ans;
vector<int> v;

// lower_bound 함수 구현, 편의를 위해 STL lower_bound와는 다르게 하한의 주소값이 아닌 인덱스를 반환
int low_bound(int s, int e, int val) {

	while (s <= e) {
		int mid = (s + e) / 2;

		if (v[mid] >= val) e = mid - 1;
		else s = mid + 1;
	}
	return s;
}

// upper_bound 함수 구현, 편의를 위해 STM upper_bound와는 다르게 상한의 주소값이 아닌 인덱스를 반환
int up_bound(int s, int e, int val) {

	while (s <= e) {
		int mid = (s + e) / 2;

		if (v[mid] <= val) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++)
		for (int j = i + 1; j < v.size(); j++) {
			int sum = v[i] + v[j];

			// STL 제공 lower_bound, upper_bound 함수
			//int idx1 = lower_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();
			//int idx2 = upper_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();

			// 직접 구현한 low_bound, up_bound 함수
			int idx1 = low_bound(j + 1, v.size() - 1, -sum);
			int idx2 = up_bound(j + 1, v.size() - 1, -sum);
			ans += idx2 - idx1;
		}

	cout << ans;
}
