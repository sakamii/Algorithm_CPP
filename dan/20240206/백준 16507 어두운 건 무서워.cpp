#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int n, m, k;
int a1, b1, a2, b2;
int prefixsum[1001][1001] = { 0 };

int main() {
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	// 초기값 설정;
	for (int i = 0; i < n; i++) {
		prefixsum[i + 1][1] = arr[i][0];
	}
	// 행 방향 합 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			prefixsum[i + 1][j + 1] = prefixsum[i + 1][j] + (arr[i][j]);
		}
	}
	// 열 방향 합 구하기
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			prefixsum[j + 1][i + 1] = prefixsum[j][i + 1] + prefixsum[j + 1][i + 1];
		}
	}
	// 부분합 구하기
	for (int i = 0; i < k; i++) {
		cin >> a1 >> b1 >> a2 >> b2;
		int sumall = prefixsum[a2][b2] - prefixsum[a2][b1 - 1] - prefixsum[a1 - 1][b2] + prefixsum[a1 - 1][b1 - 1];
		cout << sumall / ((a2 - a1 + 1) * (b2 - b1 + 1))<<endl;
	}
}
