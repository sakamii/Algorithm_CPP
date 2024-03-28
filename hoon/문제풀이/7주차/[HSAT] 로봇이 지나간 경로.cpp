#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
/*

BFS를 한번만 수행하면 되는 문제인데
접근을 잘못해서 처음부터 다시 풀었다.
또한 로봇이 한번에 움직이는 거리는 2이기 때문에
1과 2 모두를 visited 체크해줘야함
예를들어
101 이런 상태면, 중간에 0임에도 불구하고 거리가 2차이나는 곳을 방문할수 있다고
처리하게 되니까, 1,2모두를 visited 처리하고, 1, 2 모두가 지나갈수 있는 곳인지도 체크하고 넘어가야함.

BFS 시작점을 찾는것이 중요
#을 상하좌우로 비교 해서 현재위치 제외 #이 1개만 나오는 곳이 시작 or 탈출지점
길을 따라간다는것이 보장되어있어서, 한 위치에서 BFS 돌리면 끝.

*/
int h, w;
int visited[26][26];
string map[26];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char direct[] = {'>', 'v', '<', '^'};
bool check(int sy, int sx)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = sy + dy[i];
        int nx = sx + dx[i];

        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            continue;
        if (map[ny][nx] == '#')
        {
            cnt++;
        }
        if (cnt > 1)
            return false;
    }

    return true;
}

struct temp
{
    int y, x, dir;
};
string load = "";
void bfs(int sy, int sx, int dir)
{
    queue<temp> q;
    visited[sy][sx] = 1;
    q.push({sy, sx, dir});

    while (!q.empty())
    {
        int cy = q.front().y;
        int cx = q.front().x;
        int cdir = q.front().dir;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i] * 2;
            int nx = cx + dx[i] * 2;
            if (ny < 0 || nx < 0 || ny >= h || nx >= w)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            if (map[cy + dy[i]][cx + dx[i]] == '#' && map[ny][nx] == '#')
            {
                visited[cy + dy[i]][cx + dx[i]] = 1;
                visited[ny][nx] = 1;
                if (i == cdir)
                {
                    load.push_back('A');
                }
                else
                {
                    if (cdir == 0 && i == 3)
                    {
                        load.push_back('L');
                    }
                    else if (cdir == 3 && i == 0)
                    {
                        load.push_back('R');
                    }
                    else
                    {
                        if (i < cdir)
                        {
                            load.push_back('L');
                        }
                        else
                        {
                            load.push_back('R');
                        }
                    }
                    load.push_back('A');
                }
                q.push({ny, nx, i});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> map[i];
    }
    int start_y, start_x, start_dir;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == '#' && check(i, j))
            {
                start_y = i;
                start_x = j;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = start_y + dy[i];
        int nx = start_x + dx[i];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            continue;
        if (map[ny][nx] == '#')
        {
            bfs(start_y, start_x, i);
            start_dir = i;
        }
    }
    cout << start_y + 1 << " " << start_x + 1 << endl;
    cout << direct[start_dir] << endl;
    cout << load << endl;
}