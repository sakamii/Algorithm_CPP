#include <iostream>
#include <queue>
using namespace std;

int n, m, k, r, c, ans, v[102][102];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
bool vis[102][102];

void bfs(int X, int Y) {
    vis[X][Y] = 1;
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ X,Y });

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!nx || !ny || nx > n || ny > m) continue;

            if (!vis[nx][ny] && v[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }
    ans = max(ans, cnt);
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        v[r][c] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (v[i][j] && !vis[i][j]) bfs(i, j);

    cout << ans;
}
