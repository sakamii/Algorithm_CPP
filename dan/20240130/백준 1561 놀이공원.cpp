#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n, t[100001], max_value = 0, answer=0;
// 시간을 딱 받고 나서 애들이 모두 타고 나왔는지 확인하고 딱 n명이 타고 나온 시간이 나오면
// 이때 멈추고 얘로 나눠 떨어지는 애들 중에 가장 큰 수를 answer로 내보냄

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		max_value += t[i];
	}
	int left = 0, right = max_value * ceil(n / m), mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int mt = 0;
		for (int i = 0; i < m; i++) {
			mt += mid / t[i];
		}
		if (mt > m) {
			right = mid - 1;
		}
		else if (mt < m) {
			left = mid + 1;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		if (mid % t[i] == 0)
			answer = max(answer, t[i]);
	}
	cout << answer;
}
