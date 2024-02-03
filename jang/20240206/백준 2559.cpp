//백준 2559 슬라이딩 윈도우, 누적합 배열 사용
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int sumArray[100001];

int main() {
	int N, K, a, temp, answer=INT_MIN;
	cin >> N >> K;
	sumArray[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		sumArray[i] = sumArray[i - 1] + a;
	}
	
	for (int i = K; i <= N; i++) {
		temp = sumArray[i] - sumArray[i - K];
		answer = max(temp, answer);
	}

	cout << answer;
}
