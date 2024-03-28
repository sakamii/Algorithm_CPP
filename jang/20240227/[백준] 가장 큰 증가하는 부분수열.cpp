#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int DP[1001];
int arr[1001];
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		DP[i] = arr[i];
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j] && DP[i] < DP[j] + arr[i]) {
				DP[i] = DP[j] + arr[i];
			}
		}
		answer = max(DP[i], answer);
	}
	cout << answer;
}