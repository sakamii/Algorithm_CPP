#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string arr[334];
	int n, m, max_mn = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int prefixsum[335][335] = { 0 };
	// 초기값 설정;
	for (int i = 0; i < n; i++) {
		prefixsum[i+1][1] = (arr[i][0]-'0');
	}
	// 행 방향 합 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			prefixsum[i+1][j+1] = prefixsum[i+1][j] + (arr[i][j]-'0');
		}
	}
	// 열 방향 합 구하기
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			prefixsum[j+1][i+1] = prefixsum[j][i+1] + prefixsum[j+1][i+1];
		}
	}
	// 여기서 시간초과 뜸 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int y = 1; y < n+1; y++) {
				for (int x = 1; x < m+1; x++) {
					if (y <= i || x <= j) continue;
					int max_value = prefixsum[y][x] - prefixsum[y][j] - prefixsum[i][x] + prefixsum[i][j];
					if (max_value == 0) {
						if ((y - i) * (x - j) > max_mn) max_mn = (y - i) * (x - j);
						int de = -1;
					}
				}
			}
		}
	}
	cout << max_mn;
}
