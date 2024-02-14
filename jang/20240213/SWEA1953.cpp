//탈주범검거
#include <iostream>
#include <queue>
using namespace std;

int N, M, R, C, L;

int map[50][50];
bool visited[50][50];
int answer;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int doNotGo[4][3] = { { 2,4,5 } ,{ 2,6,7 } ,{ 3,4,7 }, { 3,5,6 } };

struct Node {
	int x, y, nowSecond;
};
void BFS() {
	queue<Node>q;
	q.push({R,C,1});
	visited[R][C] = true;
	while (!q.empty()) {
		int nowx = q.front().x;
		int nowy = q.front().y;
		int nowSecond = q.front().nowSecond;
		q.pop();
		if (nowSecond == L) continue;
		if (map[nowx][nowy] == 1) {
			for (int i = 0; i < 4; i++) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || map[nx][ny] == 0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny, nowSecond+1});
					visited[nx][ny] = true;
				}
			}
		}
		else if (map[nowx][nowy] == 2) {
			for (int i = 2; i < 4; i++) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || map[nx][ny] == 0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny, nowSecond+1 });
					visited[nx][ny] = true;
				}
			}
		}
		else if (map[nowx][nowy] == 3) {
			for (int i = 0; i < 2; i++) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || map[nx][ny] == 0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny,nowSecond+1 });
					visited[nx][ny] = true;
				}
			}
		}
		else if (map[nowx][nowy] == 4) {
			for (int i = 0; i < 4; i+=2) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || map[nx][ny] == 0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny,nowSecond+1 });
					visited[nx][ny] = true;
				}
			}
		}
		else if (map[nowx][nowy] == 5) {
			for (int i = 0; i < 4; i+=3) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || map[nx][ny] == 0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny,nowSecond+1 });
					visited[nx][ny] = true;
				}
			}
		}
		else if (map[nowx][nowy] == 6) {
			for (int i = 1; i < 4; i+=2) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]||map[nx][ny] == 0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny,nowSecond+1 });
					visited[nx][ny] = true;
				}
			}
		}
		else {
			for (int i = 1; i < 3; i++) {
				int nx = nowx + dx[i];
				int ny = nowy + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]||map[nx][ny]==0) {
					continue;
				}
				bool can = true;
				for (int elem : doNotGo[i]) {
					if (map[nx][ny] == elem) {
						can = false;
						break;
					}
				}
				if (can) {
					q.push({ nx,ny,nowSecond+1 });
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		answer = 0;
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		BFS();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j]) answer++;
			}
		}
		cout << '#' << x << ' ' << answer << '\n';
	}
	
}
