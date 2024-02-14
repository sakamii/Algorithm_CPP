#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M, answer;
int arr[16][16];
bool visited[16][16];
vector<vector<int>>dx = { { -1,-1,-1,0,0,1 }, { 1, 1, 1, 0, 0, -1} };
vector<vector<int>>dy = { { -1,0,1,-1,1,0} ,{-1, 0, 1, 1, -1, 0 } };
int firstdx[5][3] = { {0,0,1},{0,0,-1},{-1,0,1},{-1,0,1}, };
int firstdy[5][3] = { {1,2,1},{1,2,1},{0,1,0},{0,-1,0} };

void DFS(int a, int b, int nowtemp, int num) {
	nowtemp += arr[a][b];
	if (num == 4) {
		answer = max(nowtemp, answer);
		return;
	}
	int dtemp = b % 2;
	for (int i = 0; i < dx[dtemp].size(); i++) {
		int nx = a + dx[dtemp][i];
		int ny = b + dy[dtemp][i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) {
			continue;
		}
		visited[nx][ny] = true;
		DFS(nx, ny, nowtemp, num + 1);
		visited[nx][ny] = false;
	}
}

void DFS2(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int sumTemp = arr[a][b];
		for (int j = 0; j < 3; j++) {
			int nx = a + firstdx[i][j];
			int ny = b + firstdy[i][j];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
			sumTemp += arr[nx][ny];
		}
		answer = max(sumTemp, answer);
	}
	if (b % 2 == 1) {
		if (a + 2 >= N || b + 1 >= M) {
			return;
		}
		int sumTemp = arr[a][b] + arr[a+1][b]+arr[a+2][b-1]+arr[a+2][b+1];
		answer = max(sumTemp, answer);
		if (a + 2 >= N || b + 2 >= M) {
			return;
		}
		sumTemp = arr[a][b] + arr[a][b + 2] + arr[a + 1][b + 1] + arr[a + 2][b + 1];
		answer = max(sumTemp, answer);
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		answer = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				DFS2(i, j);
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = true;
				DFS(i, j, 0, 1);
				visited[i][j] = false;
			}
		}

		cout << '#' << x << ' ' << answer << '\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
	}
}
