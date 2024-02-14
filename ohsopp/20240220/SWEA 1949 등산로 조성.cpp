
#include <iostream>
#include <vector>
using namespace std;
 
int t, n, k, maxh, ans, arr[10][10];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
bool vis[10][10];
vector<pair<int, int>> v[21];
 
void dfs(int x, int y, int h, int d, bool cut) {
    ans = max(ans, d);
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!nx || !ny || nx > n || ny > n || vis[nx][ny]) continue;
 
        if (arr[nx][ny] < h) {
            vis[nx][ny] = 1;
            dfs(nx, ny, arr[nx][ny], d + 1, cut);
            vis[nx][ny] = 0;
        }
 
        if (!cut && arr[nx][ny] >= h && arr[nx][ny] - k < h) {
            vis[nx][ny] = 1;
            dfs(nx, ny, arr[x][y] - 1, d + 1, true);
            vis[nx][ny] = 0;
        }
    }
}
 
int main() {
    cin >> t;
     
    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> k;
 
        for(int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
                v[arr[i][j]].push_back({ i,j });
                maxh = max(maxh, arr[i][j]);
            }
 
        for (int i = 0; i < v[maxh].size(); i++) {
            int x = v[maxh][i].first, y = v[maxh][i].second;
            vis[x][y] = 1;
            dfs(x, y, maxh, 1, false);
            vis[x][y] = 0;
        }
        cout << "#" << tc << " " << ans << endl;
 
        ans = maxh = 0;
        for (int i = 1; i <= 20; i++)
            v[i].clear();
    }
}
