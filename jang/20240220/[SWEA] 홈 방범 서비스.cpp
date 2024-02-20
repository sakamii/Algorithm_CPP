#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int board[21][21];
bool visited[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int BFS(int x, int y, int len)
{

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    queue<pair<int, int> > q;
    q.push({x,y});
    int homecnt = 0;
    visited[x][y] = true;
    while (!q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        if (board[nowx][nowy] == 1) homecnt += 1;

        for (int k = 0; k < 4; k++) {
            int nx = nowx + dx[k];
            int ny = nowy + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
            int dist = abs(x - nx) + abs(y - ny);
            if (dist >= len) continue;
            q.push({ nx,ny });
            visited[nx][ny] = true;
        }
    }

    return homecnt;
}

int main()
{
    int tc;
    cin >> tc;
    for (int x = 1; x <= tc; x++) {
        cin >> N >> M;
        int count1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
                if (board[i][j] == 1) count1 += 1;
            }
        }
        int maxK = 1;
        while (maxK * maxK + (maxK - 1) * (maxK - 1) <= count1 * M)
            maxK += 1;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 1; k <= maxK; k++) {
                    int tempcnt = BFS(i, j, k);
                    if (tempcnt * M >= k * k + (k - 1) * (k - 1)) {
                        if (tempcnt > ans) ans = tempcnt;
                    }
                }
            }
        }
        cout << "#" << x << " " << ans << endl;
    }
}
