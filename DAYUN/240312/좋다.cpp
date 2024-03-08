#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, res, v[2001];
map<int, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }

    // res -= m[0] * (n - m[0]);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if((!m[v[i]] || !m[v[j]]) && m[v[i] + v[j]]) {
                res--;
            }
            if (m[v[i] + v[j]]) {
                res += m[v[i] + v[j]];
                m[v[i] + v[j]] = 0;
            }
        }
    }

    cout << res;
}