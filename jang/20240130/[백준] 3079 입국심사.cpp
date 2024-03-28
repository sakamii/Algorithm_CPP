#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<long long>A(N);
  //e 최악의 경우 : 10^9 * 10^9
	long long s = 1, e = pow(10,18);
	long long t = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	long double temp = 0; //하,,,,
	long long mid;
	while (s <= e) {
		mid = (s + e) / 2;
		temp = 0;
		for (int i = 0; i < A.size(); i++) {
			temp += mid / A[i];
		}
		if (temp >= M) {
			e = mid - 1;
			t = mid;
		}
		else s = mid + 1;
	}
	cout << t;
}
