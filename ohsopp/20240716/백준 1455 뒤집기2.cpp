#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;
vector<int> v[101];

void filp(int x, int y) {
    ans++;
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            v[i][j] = !v[i][j];
}

int main() {
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '0') v[i].push_back(0);
            else v[i].push_back(1);

    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            if (v[i][j]) filp(i, j);

    cout << ans;
}
