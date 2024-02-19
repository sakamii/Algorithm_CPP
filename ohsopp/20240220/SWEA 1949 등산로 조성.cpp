
/*
 최고 높이에서 dfs를 시작해야 하므로 입력 받을 때 높이별 좌표값들을 v에 저장
 dfs 재귀를 두 개로 나누는데, (1)다음 위치가 현재보다 낮은 경우와 (2)아직 높이를 안 깎았다면 다음 위치의 높이를 깎는 dfs로 진행
*/

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

        if (arr[nx][ny] < h) {    (1) 다음 위치가 현재보다 낮은 경우 => 평범하게 탐색
            vis[nx][ny] = 1;
            dfs(nx, ny, arr[nx][ny], d + 1, cut);
            vis[nx][ny] = 0;
        }
 
        if (!cut && arr[nx][ny] >= h && arr[nx][ny] - k < h) {  (2) 다음 위치가 현재보다 높으면서, 깎을 수 있는 높이가 현재보다 낮고, 아직 안 깎았다면 깎고 탐색
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
