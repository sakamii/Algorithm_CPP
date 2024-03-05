#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[350][350] = { 0 };
int t, n, m, k, alive, dead;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
struct cell {
	int y;
	int x;
	int t;
	int condition;
};
vector<cell>cells;
struct cmp {
	bool operator()(cell a, cell b) {
		return a.condition < b.condition;
	}
};
priority_queue<cell, vector<cell>, cmp>activate;

void bfs() {
	while (!activate.empty()) {
		cell now = activate.top();
		activate.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (map[ny][nx] == 0) {
				map[ny][nx] = 1;
				cells.push_back({ ny, nx, now.condition, now.condition });
				alive++;
			}
		}
	}
}

void solution() {
	while (k >= 0) {
		k--;
		for (int i = 0; i < alive; i++) {
			cells[i].t--;
			if (cells[i].t == -1) {
				activate.push({ cells[i] });
			}
			if (cells[i].t == -cells[i].condition) dead++;
		}
		bfs();
	}
}


int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cells.clear();
		alive = 0; dead = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < 350; i++)
			for (int j = 0; j < 350; j++)
				map[i][j] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a;
				cin >> a;
				map[i + 150][j + 150] = 1;
				if (a > 0) {
					cells.push_back({ i + 150,j + 150,a,a });
					alive++;
				}
			}
		}
		int de = -1;
		solution();
		cout <<"#"<<tc<<" "<< alive - dead<< endl;
	}
}
