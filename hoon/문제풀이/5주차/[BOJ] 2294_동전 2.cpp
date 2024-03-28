#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define mini 123456789
using namespace std;
int n, k;
vector<int> v;
vector<int> dp;
/*
DP문제에 대해서 조금 눈이 떠지는 문제였던것 같다.
DP문제는 정말 어렵고 생소한 부분이 아니면 비슷한 형식을 띄고있는데
그중에 대표적인 유형이 이런 동전 유형이라고 생각한다.

특정 K라는 값에 대해서, 최소 or 최댓값을 구하는 문제들이 많은데
그때, dp 테이블을 i라는 가격에서의 최솟값으로 잡게 되면 아래의 코드와 같이
이전에 구한 최솟값 + 1과 현재와의 min 값으로 해결이 가능하게 된다.

ex) k가 15원이라고 가정하면
1원짜리 동전으로 만들수 있는 dp테이블은 다음과 같다
가격 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
갯수 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

5원짜리 동전으로 만들수 있는 dp 테이블
가격 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
갯수 0 1 2 3 4 1 2 3 4 5  2  3  4  5  6  3

이 테이블을 잘 살펴보면
dp[5] = dp[5-5] + 1 의 형태를 띄고 있는걸 확인이 가능하다.

즉 더 낮은 가격에서 구한 최솟값 + 1과 이전 최솟값을 비교해 min값을 구하면 됨.

dp[i] = min(dp[i], dp[i-k] + 1) => 여기서 k는 현재 동전의 가격 ~ 주어진 K값까지.
최댓값도 동일하게 maximum 연산을 통해 해결이 가능할 것으로 보인다
*/
int main()
{
    cin >> n >> k;
    v.resize(n + 1, 0);
    dp.resize(k + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i] = mini;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }

    if (dp[k] == mini)
        cout << -1 << endl;
    else
        cout << dp[k];
    return 0;
}
