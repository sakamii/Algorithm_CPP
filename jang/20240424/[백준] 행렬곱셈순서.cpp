//행렬 곱셈 순서
#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[510][2];
int dp[510][510];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	//행렬 개수
	for (int i = 1; i < N; i++) {
		//j가 시작점으로 생각
		for (int j = 1; i + j <= N; j++) {
			dp[j][i + j] = 2e9;
			//기준점으로 계산한다.
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j]
					+ arr[j][0] * arr[k][1] * arr[i + j][1]);
			}
		}
	}
	//최종적으로 1~N까지의 최소 출력
	cout << dp[1][N];
}
