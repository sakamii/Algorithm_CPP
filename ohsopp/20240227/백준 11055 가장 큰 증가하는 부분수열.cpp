
// https://www.acmicpc.net/problem/11055

/*
최장 증가 부분 수열(LIS, Longest Incresing Subsequence)의 대표적인 문제이면서,
DP에서 몇 안되는 정형적인 문제 해결 방법 중 하나이다.
LIS와 유사한 문제로 최장 공통 부분 수열(LCS), 최장 바이토닉 부분 수열 등이 있다.

dp[i]: i번째 원소를 포함할 때 만들어지는 증가 부분 수열 총합의 최댓값을 의미.
a[j] < a[i]: a[i]보다 j번째(0 <= j < i) 원소 a[j]가 작다면 dp[i]는 max(dp[i], dp[j] + a[i])의 값을 갖는다.

직관적으로,
현재까지의 LIS의 총합(=dp[i]) > 이전의 LIS의 총합(=dp[j]) + 현재 원소(=a[i])
이라면 갱신되는 것이다.
이때 LIS의 조건을 만족하기 위해 a[i] > a[j]를 만족해야 한다.
*/

#include <iostream>
using namespace std;

int n, ma, a[1001], dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
		for (int j = 0; j < i; j++)
			if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
    }

	for (auto k : dp) ma = max(ma, k);
	cout << ma;
}
