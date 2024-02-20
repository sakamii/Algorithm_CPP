#include <iostream>
#include <queue>
using namespace std;
int t, n, m, ans, ppl;
int map[21][21];
int ydir[] = { -1,0,1,0 };
int xdir[] = { 0,1,0,-1 };
struct node {
    int y;
    int x;
    int len;
};

void bfs(int y, int x, int lev) {
    queue<node>q;
    int visited[21][21] = { 0 };
    visited[y][x] = 1;
    q.push({ y, x, lev });
    int cost = 1;

    if (ppl * m - cost >= 0) ans = max(ans, ppl);

    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.len == n + 1)break;
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
            if (visited[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            ppl += map[ny][nx];
            cost = (now.len + 1) * (now.len + 1) + now.len * now.len;
            int earn = ppl * m;
            if (earn - cost >= 0) ans = max(ans, ppl);
            q.push({ ny, nx, now.len + 1 });
        }
    }
}

int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1)ppl = 1;
                else ppl = 0;;
                bfs(i, j, 1);

            }
        }
        cout << "#" << tc << " " << ans << endl;
    }
}
