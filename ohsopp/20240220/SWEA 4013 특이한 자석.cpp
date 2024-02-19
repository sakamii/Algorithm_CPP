
/*
	비트 연산을 이용하여 해결.
 	톱니의 상태는 0에서 2^8-1(255) 사이이므로 int로 충분히 표현 가능

  	비트 길이가 n일 때, 숫자 x의 비트를 오른쪽으로 k만큼 회전하고 싶으면
	((2 << n - 1) & x >> k) | ((2 << n - 1) & x << (n - k))
 
 	왼쪽으로 k만큼 회전하고 싶으면
	((2 << n - 1) & x << k) | ((2 << n - 1) & x >> (n - k))

 	톱니 3시 방향 : (x >> 1) & 1
	톱니 9시 방향 : (x >> 5) & 1
*/

#include <iostream>
using namespace std;

int t, k, ans, m, n, d, mag[6];
bool vis[6];

void rotates(int n, int d) {
	vis[n] = 1;
	int x = mag[n];

	if (d)	// 1이면 시계 방향
		mag[n] = ((255 & x >> 1) | (255 & x << 7));
	else	// 0이면 반시계 방향
		mag[n] = ((255 & x << 1) | (255 & x >> 7));
	
	if (!vis[n - 1] && (x >> 1 & 1) != (mag[n - 1] >> 5 & 1))		// (현재 톱니의 9시 != 왼쪽 톱니의 3시) 왼쪽 톱니 회전
		rotates(n - 1, !d);
	if (!vis[n + 1] && (x >> 5 & 1) != (mag[n + 1] >> 1 & 1))		// (현재 톱니의 3시 != 오른쪽 톱니의 9시) 오른쪽 톱니 회전
		rotates(n + 1, !d);

	vis[n] = 0;
}

int main() {
	cin >> t;

	vis[0] = vis[5] = 1;
	for (int tc = 1; tc <= t; tc++) {
		cin >> k;

		for (int i = 1; i <= 4; i++)
			for (int j = 7; j >= 0; j--) {
				cin >> m;
				mag[i] += m << j;
			}

		while (k--) {
			cin >> n >> d;
			rotates(n, d + 1);
		}
		
		for (int i = 1, mul = 1; i <= 4; i++, mul *= 2)
			ans += mul * (mag[i] >> 7 & 1);

		cout << "#" << tc << " " << ans << endl;
		ans = 0;
		fill(mag, mag + 6, 0);
	}
}
