
#include <iostream>
using namespace std;

int n, m, x, y, ans, arr[6][6], path[20][2];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
bool vis[6][6];

void dfs(int x, int y, int seq) {
    if (seq >= m && x == path[m][0] && y == path[m][1]) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (!nx || !ny || nx > n || ny > n) continue;

        if (!vis[nx][ny] && !arr[nx][ny]) {
            vis[nx][ny] = 1;
            if (path[seq][0] == x && path[seq][1] == y)
                dfs(nx, ny, seq + 1);
            else dfs(nx, ny, seq);
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= m; i++)
        cin >> path[i][0] >> path[i][1];

    vis[path[1][0]][path[1][1]] = 1;
    dfs(path[1][0], path[1][1], 1);
    
    cout << ans;
}
