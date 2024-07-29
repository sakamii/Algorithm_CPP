#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100002];

void bs(int x) {
	int s = 0, e = N - 1, mid = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		if (A[mid] == x) {
			cout << 1 << "\n";
			return;
		}
		else if (A[mid] < x) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << 0 << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A, A + N);
	int M, X;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> X;
		bs(X);
	}
	return 0;
}
