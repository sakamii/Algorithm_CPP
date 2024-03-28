#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
// dp => i번째 인덱스까지의 LIS.
// 현재 값과 그 이전의 index 값을 비교하면서
// 그 이전의 LIS + 현재 값이 이전의 값들보다 크면 더해줌
// => 이중포문으로 처음부터 i번째까지 탐색하면서!
// => 탐색하는 부분 binary search로 해결가능함 -> O(nlogn으로 줄이기 가능)
vector<int> dp;
int main()
{
    cin >> n;
    v.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = v[i];
        for (int j = 1; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}