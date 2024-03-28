//지역구 나누기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, total, answer;
int arr[9][9];
int person[9];
bool team[9];
bool done[9];

void DFScheck(int a) {
	done[a] = true;
	for (int i = 1; i <= N; i++) {
		if (arr[a][i] == 1 && !team[i] && !done[i]) {
			DFScheck(i);
		}
	}
}

bool check() {
	for (int i = 1; i <= N; i++) {
		done[i] = false;
	}
	for (int i = 1; i <= N; i++) {
		if (team[i]) done[i] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (!team[i]) {
			DFScheck(i);
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!done[i]) {
			return false;
		}
	}
	return true;
}

void DFS(int a,int tempSum) {
	if (!check()) {
		return;
	}
	answer = min(answer, abs(tempSum-abs(total-tempSum)));
	for (int i = 1; i <= N;i++) {
		if (arr[a][i] == 1 && !team[i]) {
			team[i] = true;
			DFS(i,tempSum+person[i]);
			team[i] = false;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		answer = 1000;
		total = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			cin >> person[i];
			total += person[i];
		}
		for (int i = 1; i <= N; i++) {
			team[i] = false;
		}
		for (int i = 1; i <= N; i++) {
			team[i] = true;
			DFS(i, person[i]);
			team[i] = false;
		}
		cout << '#' << x << ' ' << answer << '\n';
	}
	
	
}
