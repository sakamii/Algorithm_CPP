
// https://www.acmicpc.net/problem/2559

#include <iostream>
using namespace std;

int n, k, r, ans = -1e9, v[100005];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    for (int i = k; i <= n; i++)
        ans = max(ans, v[i] - v[i - k]);

    cout << ans;
}
