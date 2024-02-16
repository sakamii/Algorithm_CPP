// SWEA 5648 원자 소멸 시뮬레이션

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>

using namespace std;

struct edge {
	int x;
	int y;
	int dir;
	int K;
};

int ydir[4] = { 1, -1, 0, 0 };
int xdir[4] = { 0, 0, -1, 1 };

int map[2001][2001];
vector<edge> atoms;

// 모든 원자들의 이동속도는 동일
//최초의 위치에서 이동
//두개의 원자ㅏ가  충돌할 경우 보유한 에느ㅓ지를 방출하고 소멸
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0;
		int N;
		memset(map, -1, sizeof(map));
		cin >> N;
		atoms.resize(N);
		for (int i = 0; i < N; i++) {
			int x, y, dir, k;
			cin >> x >> y >> dir >> k;
			x += 1000;
			y += 1000;
			atoms[i] = { x, y, dir, k };
			map[y][x] = i;
		}

		int remove = 0;
		while (remove < N) {
			for (int i = 0; i < N; i++) {
				// cout << "?" << endl;
				// cout << i << atoms[i].y << atoms[i].x << atoms[i].dir << result << " ?";
				// cout << remove << endl;
				if (atoms[i].y == -1) continue;
				int y = atoms[i].y;
				int x = atoms[i].x;
				int dir = atoms[i].dir;
				int next_y = y + ydir[dir];
				int next_x = x + xdir[dir];
				// if (i == 0) cout << x;

				if ((next_y >= 0) && (next_y <= 2000) && (next_x >= 0) && (next_x <= 2000)) {
					bool flag = false;
					for (int d = 0; d < 4; d++) {
						if (((next_y - ydir[d]) < 0) || ((next_y - ydir[d]) > 2000) || ((next_x - xdir[d]) < 0) || ((next_x - xdir[d]) > 2000)) continue; 
						int m = map[next_y - ydir[d]][next_x - xdir[d]];
						if ((m > 0) && (m != i) && (atoms[m].dir == d)) {
							result += atoms[m].K;
							map[next_y - ydir[d]][next_x - xdir[d]] = 0;
							atoms[m].y = -1;
							flag = true;
							remove++;
						}
					}
					if (map[next_y][next_x] >= 0) {
						int dir1 = atoms[map[next_y][next_x]].dir;
						if ((xdir[dir] + xdir[dir1] + ydir[dir] + ydir[dir1]) == 1) {
							result += atoms[map[next_y][next_x]].K;
							atoms[map[next_y][next_x]].y = -1;
							map[next_y][next_x] = 0;
							flag = true;
							remove++;
						}
					}

					if (flag) {
						result += atoms[i].K;
						atoms[i].y = -1;
						flag = true;
						map[y][x] = 0;
						remove++;
					}
					else {
						map[y][x] = 0;
						map[next_y][next_x] = i;
						atoms[i].y = next_y;
						atoms[i].x = next_x;
					}
				}
				else {
					remove++;
					map[y][x] = 0;
					atoms[i].y = -1;
				}

			}
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}