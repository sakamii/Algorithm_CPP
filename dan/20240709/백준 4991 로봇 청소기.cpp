#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include<climits>
using namespace std;
int sy, sx, ans;
int w, h;
char map[21][21];
int dist[11][21][21] = { 0 }; // 각 쓰레기로부터 쓰레기까지의 거리
struct nodes
{
	int y, x;
};
vector<nodes>dirt;
int dir[2][4] = { {-1,1,0,0},{0,0,-1,1} };
void bfs(int y, int x, int vis[21][21]);
int vis[21][21] = { 0 };
int toDirt[11] = { 0 }; // 출발부터 쓰레기까지의 거리

int main() {
	while (true) {
		ans = INT_MAX; vector<int>order;
		cin >> w >> h;
		if (w == 0 and h == 0) break;
		// 썻던거 돌려놓기
		fill(&vis[0][0], &vis[0][0] + 21 * 21, 0);
		for (int i = 0; i < 11; i++)
			fill(&dist[i][0][0], &dist[i][0][0] + 21 * 21, 0);
		dirt.clear();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char a;
				cin >> a;
				map[i][j] = a;
				if (a == 'o') {
					sy = i; sx = j;
				}
				else if (a == '*') {
					dirt.push_back({ i,j });
				}
			}
		}
		// 출발점부터 각 먼지까지의 거리를 구함
		bfs(sy, sx, vis);
		for (int i = 0; i < dirt.size(); i++) {
			toDirt[i] = vis[dirt[i].y][dirt[i].x];
			// 만약에 갈 수 없는 곳이 있다면 ans = -1;
			if (toDirt[i] == 0) ans = -1;
			// 먼지끼리의 거리를 구함 
			bfs(dirt[i].y, dirt[i].x, dist[i]);
			order.push_back(i);
		}
		int de = -1;
		// next_permutation을 이용해 가능한 거리 다 구하기
		do {
			int  d = toDirt[order[0]];
			for (int i = 0; i < dirt.size() - 1; i++) {
				int now = order[i];
				int next = order[i + 1];
				d += dist[now][dirt[next].y][dirt[next].x];
			}
			ans = min(d, ans);
		} while (next_permutation(order.begin(), order.end()));
		cout << ans << endl;
	}
}

void bfs(int y, int x, int vis[21][21]) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + dir[0][i];
			int nx = nowx + dir[1][i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
			if (map[ny][nx] == 'x')continue;
			if (vis[ny][nx] != 0)continue;
			vis[ny][nx] = vis[nowy][nowx] + 1;
			q.push({ ny,nx });
		}
	}
}
