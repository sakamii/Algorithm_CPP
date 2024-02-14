
#include <iostream>
using namespace std;

int t, n, x, ans, garo, sero, idx, arr[22][22];

int main() {
	cin >> t;
  
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> x;
    
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		for (int i = 1; i <= n; i++) {
			garo = 1, sero = 1;
			for (int j = 2; j <= n; j++) {
				// 가로 -----------------------------------------------------
				if (!garo && !sero) break;

				if (arr[i][j] == arr[i][j - 1] + 1) {	// 현재가 왼쪽보다 1 클 때
					idx = j - 1;
					while (arr[i][j - 1] == arr[i][idx]) idx--;
					if (arr[i][idx] > arr[i][j - 1] && j - 1 - idx < 2 * x) garo = 0;
					else if (j - 1 - idx < x) garo = 0;
				}
				else if (arr[i][j] + 1 == arr[i][j - 1]) {	// 현재가 왼쪽보다 1 작을 때
					idx = j;
					while (arr[i][j] == arr[i][idx]) idx++;
					if (idx - j < x) garo = 0;
				}
				else if (arr[i][j] != arr[i][j - 1]) garo = 0;	// 2 이상일 때

				// 세로 -----------------------------------------------------
				if (arr[j][i] == arr[j - 1][i] + 1) {	// 현재가 위쪽보다 1 클 때
					idx = j - 1;
					while (arr[j - 1][i] == arr[idx][i]) idx--;
					if (arr[idx][i] > arr[j - 1][i] && j - 1 - idx < 2 * x) sero = 0;
					else if (j - 1 - idx < x) sero = 0;
				}
				else if (arr[j][i] + 1 == arr[j - 1][i]) {	// 현재가 위쪽보다 1 작을 때
					idx = j;
					while (arr[j][i] == arr[idx][i]) idx++;
					if (idx - j < x) sero = 0;
				}
				else if (arr[j][i] != arr[j - 1][i]) sero = 0;
			}
			ans += garo + sero;
		}

		cout << "#" << tc << " " << ans << endl;
		fill(arr[0], arr[22], 0);
		ans = 0;
	}
}
