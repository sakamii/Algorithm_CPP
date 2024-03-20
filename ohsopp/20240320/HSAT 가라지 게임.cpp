
#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;

int n, ans, arr[50][16];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void fall(int array[][16]) {
    int cnt;

    for (int j = 1; j <= n; j++) {
        cnt = 0;
        for (int i = 3 * n; i; i--) {
            if (!array[i][j]) cnt++;
            else if (cnt) {
                array[i + cnt][j] = array[i][j];
                array[i][j] = 0;
            }
        }
    }
}

int bfs(int X, int Y, int k, int array[][16]) {
    queue<pii> q;
    int sx = X, sy = Y, ex = X, ey = Y;
    array[X][Y] = 0;
    q.push({ X,Y });
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        sx = min(sx, x); ex = max(ex, x);
        sy = min(sy, y); ey = max(ey, y);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            
            if (nx <= 2 * n || !ny || nx > 3 * n || ny > n) continue;

            if (array[nx][ny] == k) {
                array[nx][ny] = 0;
                cnt++;
                q.push({ nx,ny });
            }
        }
    }
    return (ex - sx + 1) * (ey - sy + 1) + cnt;
}

void copyArr(int src[][16], int dst[][16]) {
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= n; j++)
            dst[i][j] = src[i][j];
}

void dfs(int d, int sum, int org[][16]) {

    if (d == 2) {
        for (int i = 2 * n + 1; i <= 3 * n; i++)
            for (int j = 1; j <= n; j++)
                if (org[i][j])
                    ans = max(ans, sum + bfs(i, j, org[i][j], org));

        return;
    }

    int tmp[50][16];
    copyArr(org, tmp);

    for (int i = 2 * n + 1; i <= 3 * n; i++)
        for (int j = 1; j <= n; j++)
            if (tmp[i][j]) {
                int k = bfs(i, j, tmp[i][j], tmp);
                fall(tmp);
                dfs(d + 1, sum + k, tmp);
                copyArr(org, tmp);
            }
}

int main() {
    cin >> n;

    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    
    dfs(0, 0, arr);

    cout << ans;
}
