#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int R, C, Q;
	cin >> R >> C >> Q;
	vector<vector<int>>arr(R+1, vector<int>(C+1,0));
	vector<vector<int>>accSum(R+1, vector<int>(C+1,0));
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}
	
	//누적합 배열 구하기
	accSum[1][1] = arr[1][1];
	for (int i = 2; i <= R; i++) {
		accSum[i][1] = accSum[i - 1][1] + arr[i][1];
		
	}
	for (int i = 2; i <= C; i++) {
		accSum[1][i] = accSum[1][i - 1] + arr[1][i];
	}
	for (int i = 2; i <= R; i++) {
		for (int j = 2; j <= C; j++) {
			accSum[i][j] = accSum[i - 1][j] + accSum[i][j - 1] - accSum[i - 1][j - 1] + arr[i][j];
		}
	}

	//기본 누적합 공식 적용
	int startx, starty, endx, endy;
	for (int i = 0; i < Q; i++) {
		cin >> startx >> starty >> endx >> endy;
		if (startx > endx) {
			int temp = startx;
			startx = endx;
			endx = temp;
		}
		if (starty > endy) {
			int temp = starty;
			starty = endy;
			endy = temp;
		}
		cout << (accSum[endx][endy] - accSum[startx-1][endy] - accSum[endx][starty - 1] + accSum[startx - 1][starty - 1])/
			((endy-starty+1)*(endx-startx+1)) << '\n';
	}
}
