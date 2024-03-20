#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int MAX_N = 21, UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int N, answer;

void pushBlock(int dir, int board[MAX_N][MAX_N]) {
	queue<int> q;
	switch (dir) {
		case UP: {
			for (int j = 0; j < N; j++) {
				int before = -1, after = -1;
				for (int i = 0; i < N; i++) {
					if (board[i][j] == 0) continue;
					if (before == -1) before = board[i][j];
					else {
						after = board[i][j];
						if (before == after) {
							q.push(before + after);
							before = after = -1;
						}
						else {
							q.push(before);
							before = after;
							after = -1;
						}
					}
				}
				
				if (before != -1 && after == -1) {
					q.push(before);
				}
				for (int i = 0; i < N; i++) {
					if (q.empty()) {
						board[i][j] = 0;
						continue;
					}
					board[i][j] = q.front();
					answer = max(answer, board[i][j]);
					q.pop();
				}
			}
			break;
		}
		case RIGHT: {
			for (int i = 0; i < N; i++) {
				int before = -1, after = -1;
				for (int j = N - 1; j >= 0; j--) {
					if (board[i][j] == 0) continue;
					if (before == -1) before = board[i][j];
					else {
						after = board[i][j];
						if (before == after) {
							q.push(before + after);
							before = after = -1;
						}
						else {
							q.push(before);
							before = after;
							after = -1;
						}
					}
				}

				if (before != -1 && after == -1) {
					q.push(before);
				}
				for (int j = N - 1; j >= 0; j--) {
					if (q.empty()) {
						board[i][j] = 0;
						continue;
					}
					board[i][j] = q.front();
					answer = max(answer, board[i][j]);
					q.pop();
				}
			}
			break;
		}
		case DOWN: {
			for (int j = 0; j < N; j++) {
				int before = -1, after = -1;
				for (int i = N - 1; i >= 0; i--) {
					if (board[i][j] == 0) continue;
					if (before == -1) before = board[i][j];
					else {
						after = board[i][j];
						if (before == after) {
							q.push(before + after);
							before = after = -1;
						}
						else {
							q.push(before);
							before = after;
							after = -1;
						}
					}
				}

				if (before != -1 && after == -1) {
					q.push(before);
				}
				for (int i = N - 1; i >= 0; i--) {
					if (q.empty()) {
						board[i][j] = 0;
						continue;
					}
					board[i][j] = q.front();
					answer = max(answer, board[i][j]);
					q.pop();
				}
			}
			break;
		}
		case LEFT: {
			for (int i = 0; i < N; i++) {
				int before = -1, after = -1;
				for (int j = 0; j < N; j++) {
					if (board[i][j] == 0) continue;
					if (before == -1) before = board[i][j];
					else {
						after = board[i][j];
						if (before == after) {
							q.push(before + after);
							before = after = -1;
						}
						else {
							q.push(before);
							before = after;
							after = -1;
						}
					}
				}

				if (before != -1 && after == -1) {
					q.push(before);
				}
				for (int j = N - 1; j >= 0; j--) {
					if (q.empty()) {
						board[i][j] = 0;
						continue;
					}
					board[i][j] = q.front();
					answer = max(answer, board[i][j]);
					q.pop();
				}
			}
			break;
		}
	}
}


void simulate(int level, int board[MAX_N][MAX_N]) {
	if (level == 5) return;
	
	for (int i = 0; i < 4; i++) {
		int cBoard[MAX_N][MAX_N];
		copy(&board[0][0], &board[N][N], &cBoard[0][0]);
		pushBlock(i, cBoard);
		simulate(level + 1, cBoard);
	}
}

int main() {
	cin >> N;
	int board[MAX_N][MAX_N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	simulate(0, board);
	cout << answer;
	return 0;
}