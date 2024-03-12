// @START 24.03.11:15:33
// @END 24.03.12:10:00
// @TOTAL 1DAY
// @TIP
// - 완전 탐색에 대한 return 기준을 살펴볼 것

#include <iostream>
#include <algorithm>
#include <tuple>
#include <limits.h>
#include <vector>

using namespace std;

vector<vector<int>> vect;
int paper[6] = { 0, 5, 5, 5, 5, 5 };
int answer = INT_MAX;

bool isPossible(int y, int x, int level) {
	for (int i = y; i < y + level; i++) {
		for (int j = x; j < x + level; j++) {
			if (i >= 10 || j >= 10) return false;
			if (vect[i][j] == 0) return false;
		}
	}
	return true;
}

void filled(int y, int x, int level, int type) {
	for (int i = y; i < y + level; i++) {
		for (int j = x; j < x + level; j++) {
			vect[i][j] = type;
		}
	}
}

bool isCovered() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (vect[i][j] == 1) return false;
		}
	}
	return true;
}

void DFS(int cnt) {
	if (isCovered()) {
		answer = min(answer, cnt);
		return;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (vect[i][j] == 0) continue;
			for (int k = 5; k > 0; k--) {
				if (vect[i][j] == 0 || paper[k] == 0) continue;
				if (isPossible(i, j, k)) {
					paper[k]--;
					filled(i, j, k, 0);
					DFS(cnt + 1);
					paper[k]++;
					filled(i, j, k, 1);
				}
			}
			return;
		}
	}
}

int main() {
	vect.resize(10, vector<int>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> vect[i][j];
		}
	}

	DFS(0);
	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}
