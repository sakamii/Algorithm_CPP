
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int n, m, a, b, c, ans;
vector<pair<int, int>> v[1001];
bool vis[1001];

void dfs(int cur, int e, int sum) {
    if (cur == e) {
        ans = sum;
        return;
    }

    for (int i = 0; i < v[cur].size(); i++)
        if (!vis[v[cur][i].first]) {
            vis[v[cur][i].first] = 1;
            dfs(v[cur][i].first, e, sum + v[cur][i].second);
        }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        memset(vis, 0, sizeof(vis));
        vis[a] = 1;
        dfs(a, b, 0);
        cout << ans << '\n';
    }
}
