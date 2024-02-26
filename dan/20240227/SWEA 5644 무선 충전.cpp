#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int t, m, a, ans;
int q, w, e, r;
int pa[1001];
int pb[1001];
vector<int> map[1001][1001];
int ydir[] = { -1,1,0,0 }, xdir[] = { 0,0,-1,1 }; 
int yd[] = { 0, -1,1,0,0 }, xd[] = { 0,0,0,-1,1 };
struct battery {
	int y;
	int x;
	int c;
	int p;
};
vector<battery>v;
void bfs(int y, int x) {
	int visited[101][101] = { 0 };
	queue<pair<int, int>>queue;
	queue.push({ y,x });
	map[y][x].push_back(r);
	visited[y][x] = 1;
	while (!queue.empty()) {
		int nowy = queue.front().first;
		int nowx = queue.front().second;
		queue.pop();
		for (int i = 0; i < 4; i++) {
			int ny = nowy + ydir[i];
			int nx = nowx + xdir[i];
			if (ny < 1 || ny>10 || nx < 1 || nx>10)continue;
			if (abs(q - ny) + abs(w - nx) > e)continue;
			if (visited[ny][nx] != 0)continue;
			// map에 저장할때 더 충전량이 큰 애가 알아서
			// 위로 올라가면 좋을텐데 pq랑 함께 쓸 수 있는 방법
			// 이 있는건지 모르겠음.
			map[ny][nx].push_back(r);
			visited[ny][nx] = 1;
			queue.push({ ny,nx });
		}
	}
}

void charge() {
	int ay = 1, ax = 1, by = 10, bx = 10;
	for (int i = 0; i < m; i++) {
		ay = ay + ydir[pa[i]];
		ax = ax + ydir[pa[i]];
		by = by + ydir[pb[i]];
		bx = bx + ydir[pb[i]];
		if (map[ay][ax].empty() && map[by][bx].empty())continue;
		else if (map[ay][ax].empty() && !map[by][bx].empty()) {
			ans += map[by][bx][0];
		}
		else if (!map[ay][ax].empty() && map[by][bx].empty()) {
			ans += map[ay][ax][0];
		}
		else {
			if (map[ay][ax].size() > 1 || map[by][bx].size() > 1) {
				// 둘 중에 하나는 하나가 많으니까
				ans += map[ay][ax][map[ay][ax].size() - 1] + map[by][bx][map[by][bx].size() - 1];
			}
			else if(map[ay][ax][0]==map[by][bx][0]) {
				ans += map[ay][ax][0];
			}
			else {
				ans += (map[ay][ax][0] + map[by][bx][0]);
			}
		}
	}
}

int main() {
    cin>>t;
    for(int tc=1;tc<=t;t++){
    	cin >> m >> a;
        for (int i = 0; i < m; i++)cin >> pa[i];
        for (int i = 0; i < m; i++)cin >> pb[i];
        for (int i = 0; i < a; i++) {
            cin >> q >> w >> e >> r;
            bfs(q, w);
        }
        charge();
        cout << "#"<<tc<<" "<<ans;
    }
}
