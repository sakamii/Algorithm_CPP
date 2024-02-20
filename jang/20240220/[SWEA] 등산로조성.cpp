#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[9][9];
int N, tc, K, answer, maxNum;
vector<pair<int,int>>temp;
vector<pair<int, int>>topMountain;
bool visited[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void DFS(int a, int b, int chance) {
	visited[a][b] = true;
	temp.push_back({ a,b });
	if (chance) {
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) {
				continue;
			}
			if (A[nx][ny] < A[a][b]) {
				DFS(nx, ny, 1);
			}
			else {
				if (A[nx][ny] - K <= A[a][b] - 1) {
					int tem1 = A[nx][ny];
					A[nx][ny] = A[a][b] - 1;
					flag = true;
					DFS(nx, ny, 0);
					A[nx][ny] = tem1;
				}
			}
		}
		if (!flag) {
			int a = temp.size();
			answer = max(answer, a);
		}
	}
	else {
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) {
				continue;
			}
			if (A[nx][ny] < A[a][b]) {
				flag = true;
				DFS(nx, ny, 0);
			}
		}
		if (!flag) {
			int a = temp.size();
			answer = max(answer, a);
		}
	}
	temp.pop_back();
	visited[a][b] = false;
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		maxNum = 0;
		answer = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
				if (maxNum < A[i][j]) {
					maxNum = A[i][j];
					topMountain.clear();
					topMountain.push_back({ i,j });
				}
				else if (maxNum == A[i][j]) {
					topMountain.push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < topMountain.size(); i++) {
			DFS(topMountain[i].first, topMountain[i].second, 1);
		}

		cout << '#' <<x<<' '<< answer<<'\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j]=false;
			}
		}
		temp.clear();
		topMountain.clear();
	}
	
}

