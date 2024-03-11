#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, totalOne, answer;
int minAnswer = 2e9;
int array1[10][10];
bool visited[10][10];
int array2[6] = { 0,5,5,5,5,5 };

void origin(int a, int b, int cnt) {
	for (int i = a; i < a + cnt; i++) {
		for (int j = b; j < b + cnt; j++) {
			visited[i][j] = false;
		}
	}
}

void enter(int a, int b, int cnt) {
	for (int i = a; i < a + cnt; i++) {
		for (int j = b; j < b + cnt; j++) {
			visited[i][j] = true;
		}
	}
}

bool isPossible(int a, int b, int cnt) {
	for (int i = a; i < a + cnt; i++) {
		for (int j = b; j < b + cnt; j++) {
			if (array1[i][j] != 1 || visited[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void cal(int a, int b) {
	if (totalOne == 0) {
		int temp = 25;
		for (int i = 1; i <= 5; i++) {
			temp -= array2[i];
		}
		answer += totalOne;
		minAnswer = min(temp, minAnswer);
		answer -= totalOne;
		return;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (!visited[i][j] && array1[i][j] == 1) {
				for (int k = 1; k <= 5; k++) {
					if (!isPossible(i, j, k)) break;
					else {
						if (array2[k] == 0) continue;
						totalOne -= k * k;
						if (totalOne < 0) {
							totalOne += k * k;
							continue;
						}
						array2[k]--;
						enter(i,j,k);
						answer++;
						cal(i,j);
						answer--;
						array2[k]++;
						totalOne += k * k;
						origin(i,j,k);
					}
					
				}
				return;
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> array1[i][j];
			if (array1[i][j] == 1) totalOne++;
		}
	}
	
	cal(0, 0);
	if (minAnswer == 2e9) cout << -1;
	else cout << minAnswer;
}
