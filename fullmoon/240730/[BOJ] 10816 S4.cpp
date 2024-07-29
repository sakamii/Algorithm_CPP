#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[500002];

int upper_bound(int x) {
	int s = 0, e = N - 1, mid = 0;
	while (s <= e) {
		mid = s + (e - s) / 2;
		if (arr[mid] <= x) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return e;
}

int lower_bound(int x) {
	int s = 0, e = N - 1, mid = 0;
	while (s <= e) {
		mid = s + (e - s) / 2;
		if (arr[mid] >= x) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		cout << upper_bound(num) - lower_bound(num) + 1 << " ";
	}
	return 0;
}
