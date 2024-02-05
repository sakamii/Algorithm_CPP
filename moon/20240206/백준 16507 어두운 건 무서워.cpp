#include <iostream>
#include <algorithm>
using namespace std;

int R, C, Q;
int arr[1001][1001];
int psum[1001][1001] = { 0, };
int ans = 0;

int main() {


	cin >> R >> C >> Q;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			psum[i][j] = psum[i][j-1] + arr[i][j];
		}
	}


	for (int i = 0; i < Q; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = y1; j <= y2; j++) {
			ans += psum[j][x2] - psum[j][x1 - 1];
		}
		cout << ans / ((y2 - y1 + 1) * (x2 - x1 + 1)) << endl;
		ans = 0;
	}


	return 0;
}
