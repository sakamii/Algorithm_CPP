
#include <iostream>
#include <queue>
#include <tuple>
#define tup tuple<int, int, int>
using namespace std;

int t, n, m, r, c, l, ans, v[51][51];
int pipe[8][4] = {
    {},
    {1,1,1,1},  // 북, 동, 남, 서
    {1,0,1,0},
    {0,1,0,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1}
};
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
bool vis[51][51];

void bfs(int a, int b) {
    fill(vis[0], vis[52], 0);
    queue<tup> q;
    q.push(tup(a, b, 1));
    vis[a][b] = 1;
    
    while(!q.empty()){
        tup cur = q.front();
        q.pop();
        int x = get<0>(cur), y = get<1>(cur), c = get<2>(cur);
        
        if (c >= l) continue;
        
        for (int i = 0; i < 4; i++)
            if (pipe[v[x][y]][i]) {
                int nx = x + dx[i], ny = y + dy[i];
                int nd = (i + 2) % 4;
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || !v[nx][ny] || vis[nx][ny]) continue;
                
                if (pipe[v[nx][ny]][nd]) {
                    vis[nx][ny] = 1;
                    q.push(tup(nx, ny, c + 1));
                    ans++;
                }
            }
    }
}

int main() {
    cin >> t;
    
    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> m >> r >> c >> l;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        
        ans = 1;
        bfs(r, c);
        
        cout << "#" << tc << " " << ans << endl;
    }
}
