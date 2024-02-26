
// https://www.acmicpc.net/problem/23061

#include <iostream>
#define ll long long
using namespace std;

int n, m, w, v, b, ans, dp[100001];
ll ansv, ansb = 1;

int main() {
    cin >> n >> m;
    fill(dp + 1, dp + 100001, 1e9);
    
    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        for (int j = 100000; j >= v; j--)
            dp[j] = min(dp[j], dp[j - v] + w);
    }

    ans = 1;
    for (int i = 1; i <= m; i++) {
        cin >> b;
        for (int j = 0; j <= 100000; j++)
            if (dp[j] <= b && ansv * b < ansb * j) {
                ansv = j;
                ansb = b;
                ans = i;
            }
    }
    cout << ans;
}
