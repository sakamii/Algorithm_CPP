#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long>Arr;
long N, K;
long mid;

void BS(long s, long e) {
	if (s > e) {
		cout << e;
		return;
	}
	long mid = (s + e) / 2;
	long temp = 0;
	for (int i = 0; i < K; i++) {
		temp += Arr[i] / mid;
	}
	if (temp >= N) {
		s = mid + 1;
		BS(s, e);
	}
	else {
		e = mid - 1;
		BS(s, e);
	}
}

int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		Arr.push_back(a);
	}
	sort(Arr.begin(), Arr.end());
	long s = 1, e = Arr[Arr.size() - 1];
	if (N == 1) cout << Arr[0];
	else BS(s, e);
}
