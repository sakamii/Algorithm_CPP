#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//N은 0, S는 1
int mag[5][8];
int N,K,which,dir;
int ind[5];
bool visited[5];

void work(int workMag, int RL) {//1시계, -1 반시계
	//좌측
	visited[workMag] = true;
	if (workMag != 1 && visited[workMag-1]==false) {
		if (mag[workMag][(ind[workMag] + 8 + 6) % 8] != mag[workMag - 1][(ind[workMag-1] + 8 + 2) % 8]) {
			work(workMag - 1, -RL);
		}
	}
	if (workMag != 4 && visited[workMag + 1] == false) {
		if (mag[workMag][(ind[workMag] + 8 + 2) % 8] != mag[workMag + 1][(ind[workMag+1] + 8 + 6) % 8]) {
			work(workMag + 1, -RL);
		}
	}
	ind[workMag] = (ind[workMag] + 8 - RL) % 8;
	return;
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		cin >> K;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> mag[i][j];
			}
		}
		for (int i = 1; i <= 4; i++) {
			ind[i] = 0;
		}
		for (int i = 0; i < K; i++) {
			cin >> which >> dir;
			for (int j = 1; j <= 4; j++) {
				visited[j] = false;
			}
			work(which, dir);
		}
		int answer = 0;
		for (int i = 1; i <= 4; i++) {
			if (mag[i][ind[i]] == 1) {
				answer += pow(2, i - 1);
			}
		}
		cout << '#' << x << ' '<<answer<<'\n';
	}
	
}
