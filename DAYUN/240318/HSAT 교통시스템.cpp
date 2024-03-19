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

int ydir[] = { 0, -1, 0, 1 };
int xdir[] = { 1, 0, -1, 0 };

int road[100][100][4];
int routes[100];

vector<int> signals[13] = {
    {},
    {1, 0, 3},
    {2, 1, 0},
    {1, 2, 3},
    {2, 3, 0},
    {0, 1},
    {1, 2},
    {2, 3},
    {0, 3},
    {0, 3},
    {0, 1},
    {1, 2},
    {2, 3} };

int result = 0;
int n, t;

void dfs(int y, int x, int dir, int num_route, int tt, int route);

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> road[i][j][0] >> road[i][j][1] >> road[i][j][2] >> road[i][j][3];
        }
    }

    dfs(0, 0, 2, 1, 0, 0);
    cout << result;
}

void dfs(int y, int x, int dir, int num_route, int tt, int route)
{
    cout << tt << ":" << y << " " << x << endl;
    if (road[y][x][t % 4] / 4 != dir || (tt == t)) {
        result = max(result, num_route);
        return;
    }

    for (int signal : signals[road[y][x][t % 4]])
    {
        int nexty = y + ydir[signal];
        int nextx = x + xdir[signal];
        bool flag = false;
        if ((nexty >= 0) && (nexty < n) && (nextx >= 0) && (nextx < n))
        {
            for (int i = 0; i < route; i++) {
                if (routes[i] == (nexty * 100 + nextx)) {
                    flag = true;
                    break;
                }
            }
            routes[route] = nexty * 100 + nextx;
            if (flag) { dfs(nexty, nextx, signal, num_route, tt + 1, route + 1); }
            else { dfs(nexty, nextx, signal, num_route, tt + 1, route + 1); }
               
        }
    }

    result = max(result, num_route);

}
