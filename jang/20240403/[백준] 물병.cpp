#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	int addBottle = 0;
	while (true) {
		int nowBottleNum = N+addBottle;
		int cannotAssemble = 0;
		while (nowBottleNum > 0) {
			if (nowBottleNum % 2 == 1) {
				cannotAssemble += 1;
			}
			nowBottleNum /= 2;
		}
		if (cannotAssemble <= K) {
			break;
		}
		addBottle++;
	}
	//cout << N + addBottle;
	cout<<addBottle;
}
