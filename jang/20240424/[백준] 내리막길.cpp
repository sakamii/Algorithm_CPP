//내리막길 1520
#include <iostream>
#include <vector>
using namespace std;

int M, N, tempx, tempy, nx, ny, sum;
vector<pair<int, int>>arr1[10001];
int arr[502][502];
int answer[502][502];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void cal(pair<int,int>a) {
	tempx = a.first, tempy = a.second;
	sum = 0;
	for (int i = 0; i < 4; i++) {
		nx = tempx + dx[i], ny = tempy + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (arr[tempx][tempy] < arr[nx][ny]) {
			answer[tempx][tempy] += answer[nx][ny];
		}
	}
}

void run() {
	for (int i = 10000; i >= 1; i--) {
		if (arr1[i].size() > 0) {
			for (int j = 0; j < arr1[i].size(); j++) {
				cal(arr1[i][j]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arr1[arr[i][j]].push_back({ i,j });
		}
	}
	answer[0][0] = 1;
	run();

	cout << answer[M - 1][N - 1];
}
