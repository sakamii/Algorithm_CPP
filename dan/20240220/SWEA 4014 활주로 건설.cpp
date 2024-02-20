#include <iostream>
using namespace std;
int map[21][21];
int n, x, ans, cnt, t;

bool garo(int y, int x) {
	int i = 1;
	while (i < n) {
		// 만약 옆에꺼랑 같을 경우
		if (map[y][i] == map[y][i - 1]) cnt++;
		else if (abs(map[y][i] - map[y][i - 1]) > 1)return false;
		else if (map[y][i] > map[y][i - 1]) {
			if (cnt >= x) {
				cnt = 1;
			}
			else return false;
		}
		else if (map[y][i] < map[y][i - 1]) {
			for (int j = 0; j < x; j++) {
				// 만약에 활주로 가로 길이 충족 못해준다고 하면
				if (map[y][i] != map[y][i + j]) {
					return false;
				}
			}
			cnt = 0; // 활주로 만들어서 땅 없어짐
			i += x - 1; // 밑에 ++ 있어서 -1 빼줌
		}
		i++;
	}
	return true;
}
bool sero(int y, int x) {
	int i = 1;
	while (i < n) {
		// 만약 옆에꺼랑 같을 경우
		if (map[i][y] == map[i - 1][y]) cnt++;
		else if (abs(map[i][y] - map[i - 1][y]) > 1) return false;
		else if (map[i][y] > map[i - 1][y]) {
			if (cnt >= x) {
				cnt = 1;
			}
			else return false;
		}
		else if (map[i][y] < map[i - 1][y]) {
			for (int j = 0; j < x; j++) {
				// 만약에 활주로 가로 길이 충족 못해준다고 하면
				if (map[i][y] != map[i + j][y]) {
					return false;
				}
			}
			cnt = 0; // 활주로 만들어서 땅 없어짐
			i += x - 1; // 밑에 ++ 있어서 -1 빼줌
		}
		i++;
	}
	return true;
}


int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		// 가로로 가면서 가능한지 안한지 확인
		for (int i = 0; i < n; i++) {
			cnt = 1;
			if (garo(i, x)) ans++;
		}
		// 세로로 확인
		for (int i = 0; i < n; i++) {
			cnt = 1;
			if (sero(i, x)) ans++;
		}
		cout << "#" << tc << " " << ans << endl;
	}
}
