#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct route
{
    int y;
    int x;
    // dir : 우 상 좌 하
    int dir;
    int ver;
    int num_route;
    int t;
};

int ydir[] = { 1, 0, -1, 0 };
int xdir[] = { 0, 1, 0, -1 };

int road[100][100][4];
bool visited[100][100];

vector<int> signals[13] = {
    {},
    {2, 1, 0},
    {3, 2, 1},
    {2, 3, 0},
    {3, 0, 1},
    {2, 1},
    {3, 2},
    {3, 0},
    {0, 1},
    {1, 0},
    {2, 1},
    {2, 3},
    {3, 0} };

int result = 0;
int n, t;

void dfs(int y, int x, int dir, int tt);

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> road[i][j][0] >> road[i][j][1] >> road[i][j][2] >> road[i][j][3];
        }
    }

    visited[0][0] = true;
    dfs(0, 0, 2, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                result++;
            }
        }
    }
    cout << result;
}

void dfs(int y, int x, int dir, int tt)
{
    if (road[y][x][tt % 4] % 4 != dir || (tt == t)) {
        return;
    }

    for (int signal : signals[road[y][x][tt % 4]])
    {
        int nexty = y + ydir[signal];
        int nextx = x + xdir[signal];
        if ((nexty >= 0) && (nexty < n) && (nextx >= 0) && (nextx < n))
        {
            visited[nexty][nextx] = true;
            dfs(nexty, nextx, signal, tt + 1);
        }
    }
}
