#include <iostream>
using namespace std;

int arr[20][20];
int N, X;

bool cal(int num, int rc) {//가로 0, 세로 1
	if (rc == 0) {
		int temp = 1;
		for (int i = 0; i < N - 1; i++) {
			if (arr[num][i] == arr[num][i + 1]) temp++;
			else if (arr[num][i] == arr[num][i + 1] - 1 && temp >= X) {
				temp = 1;
			}
			else if (arr[num][i] == arr[num][i + 1] + 1 && temp >= 0) {
				temp = -X + 1;
			}
			else return 0;
		}
		if (temp >= 0) return 1;
		else return 0;
	}
	else {
		int temp = 1;
		for (int i = 0; i < N - 1; i++) {
			if (arr[i][num] == arr[i+1][num]) temp++;
			else if (arr[i][num] == arr[i + 1][num] - 1 && temp >= X) {
				temp = 1;
			}
			else if (arr[i][num] == arr[i + 1][num] + 1 && temp >= 0) {
				temp = -X + 1;
			}
			else return 0;
		}
		if (temp >= 0) return 1;
		else return 0;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (cal(i, 0)) answer++;
			if (cal(i, 1)) answer++;
		}
		cout << '#' << x << ' ' << answer << '\n';
	}
}
