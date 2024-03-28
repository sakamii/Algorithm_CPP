#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M, K;
int arr[655][655];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct cell {
	int x, y, life, activetime;
	bool operator<(cell right)const {
		return life < right.life;
	}
};
priority_queue<cell>pq;
vector<cell>cells;
void clear1() {
	for (int i = 0; i < 655; i++) {
		for (int j = 0; j < 655; j++) {
			arr[i][j] = 0;
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		clear1();
		cin >> N >> M >> K;
		for (int i = 300; i < 300 + N; i++) {
			for (int j = 300; j < 300 + M; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 0) cells.push_back({ i,j,arr[i][j],2*arr[i][j] });
			}
		}
		int diecell = 0, nowlivecell = cells.size();
		while (K != 0) {
			K--;
			for (int i = 0; i < nowlivecell; i++) {
				cells[i].activetime--;
				if (cells[i].activetime == 0) {
					diecell++;
				}
				if (cells[i].activetime == cells[i].life - 1) {
					pq.push(cells[i]);
				}
			}
			while (!pq.empty()) {
				int nowx = pq.top().x;
				int nowy = pq.top().y;
				int nowLife = pq.top().life;
				pq.pop();	
				for (int i = 0; i < 4; i++) {
					int nx = nowx + dx[i];
					int ny = nowy + dy[i];
					if (arr[nx][ny] == 0) {
						arr[nx][ny] = nowLife;
						nowlivecell++;
						cells.push_back({ nx,ny,nowLife,2*nowLife});
					}
				}
			}
			
		}
		cout << "#" << x << ' ' << nowlivecell - diecell << '\n';
		cells.clear();
		
	}
	
}
