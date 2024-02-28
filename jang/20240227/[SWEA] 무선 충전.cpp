#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[11][11];
int move1[2][100];
int M, Ax = 1, Ay = 1, Bx = 10, By = 10, I, answer;
vector<int> inf[11][11];
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };
//상 우 하 좌 1 2 3 4
//좌 하 우 상
struct AP {
	int x, y, C, P;
};
vector<AP>APs;

void cal(int x, int y, int maxN, int num) {
	for (int i = x - maxN; i <= x + maxN; i++) {
		for (int j = y - maxN; j <= y + maxN; j++) {
			if (i > 10 || j > 10 || i <= 0 || j <= 0) continue;
			if (abs(i - x) + abs(j - y) <= maxN) inf[i][j].push_back(num);
		}
	}
}

void check() {
	int temp = 0;
	if (inf[Ax][Ay].size() == 0 && inf[Bx][By].size() == 0) return;
	else if (inf[Ax][Ay].size() == 0) {
		temp = APs[inf[Bx][By][0]].P;
		for (int i = 1; i < inf[Bx][By].size(); i++) {
			temp = max(temp, APs[inf[Bx][By][i]].P);
		}
	}
	else if (inf[Bx][By].size() == 0) {
		temp = APs[inf[Ax][Ay][0]].P;
		for (int i = 1; i < inf[Ax][Ay].size(); i++) {
			temp = max(temp, APs[inf[Ax][Ay][i]].P);
		}
	}
	else {
		for (int i = 0; i < inf[Ax][Ay].size(); i++) {
			for (int j = 0; j < inf[Bx][By].size(); j++) {
				if (inf[Ax][Ay][i] == inf[Bx][By][j]) {
					temp = max(temp, APs[inf[Ax][Ay][i]].P);
					continue;
				}
				temp = max(temp, APs[inf[Ax][Ay][i]].P + APs[inf[Bx][By][j]].P);
			}
		}
	}
	answer += temp;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		cin >> M >> I;
		for (int j = 0; j < M; j++) {
			cin >> move1[0][j];
		}
		for (int j = 0; j < M; j++) {
			cin >> move1[1][j];
		}

		for (int i = 1; i <= I; i++) {
			AP a;
			cin >> a.y >> a.x >> a.C >> a.P;
			APs.push_back(a);
		}

		for (int i = 0; i < APs.size(); i++) {
			cal(APs[i].x, APs[i].y, APs[i].C, i);
		}

		check();
		for (int i = 0; i < M; i++) {
			Ax += dx[move1[0][i]];
			Ay += dy[move1[0][i]];
			Bx += dx[move1[1][i]];
			By += dy[move1[1][i]];
			check();
		}
		cout << '#' << x << ' ' << answer <<'\n';
		memset(inf, 0, sizeof(inf));
		APs.clear();
		Ax = 1, Ay = 1, Bx = 10, By = 10, answer=0;
	}
	
}




