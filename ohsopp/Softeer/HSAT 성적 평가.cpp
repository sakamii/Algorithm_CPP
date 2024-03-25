
// 이분 탐색 풀이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a;
int ans[4][100001];
int sum[100001];
vector<pair<int, int>> v[4];

int lower(int s, int e, int row, int tar) {
    int mid;

    while (s <= e) {
        mid = (s + e) / 2;

        if (v[row][mid].first <= tar) e = mid - 1;
        else s = mid + 1;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            v[i].push_back({ a,j });
            sum[j] += a;
        }
        sort(v[i].begin(), v[i].end(), greater<>());
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            ans[i][v[i][j].second] = lower(0, n - 1, i, v[i][j].first) + 1;

    for (int i = 0; i < n; i++)
        v[3].push_back({ sum[i],i });

    sort(v[3].begin(), v[3].end(), greater<>());

    for (int i = 0; i < n; i++)
        ans[3][v[3][i].second] = lower(0, n - 1, 3, v[3][i].first) + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
