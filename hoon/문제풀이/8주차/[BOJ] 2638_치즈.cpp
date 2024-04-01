#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int map[101][101];
int visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> borders;

/*
치즈의 외각 가장자리는 무조건 비어있다고 주어짐 => 0이라는뜻
치즈로 둘러싸진 외벽의 내부 빈공간은 빈공간으로 count안함 => 치즈의 외각 테두리를 구해야함
=> (0,0)즉, 0인 부분을 bfs로 탐색하고 1과 만나는 부분을 vector에 삽입 => 치즈의 외각
=> 치즈와 맞닿는 공간에서 visited를 검사해야 내부에 공기와 닿지 않는 공간도 고려 가능.
*/
void bfs(int sy, int sx)
{
    visited[sy][sx] = 1;
    queue<pair<int, int>> q;
    q.push({sy, sx});

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            if (map[ny][nx] == 1)
            {
                borders.push_back({ny, nx});
                continue;
            }
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

bool check(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (map[ny][nx] == 0 && visited[ny][nx] == 1)
            cnt++;
    }
    return cnt >= 2;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int time = 0;
    while (true)
    {
        time++;
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        borders.clear();
        bfs(0, 0);

        if (borders.size() == 0)
            break;
        else
        {
            for (int i = 0; i < borders.size(); i++)
            {
                if (check(borders[i].first, borders[i].second))
                {
                    map[borders[i].first][borders[i].second] = 0;
                }
            }
        }
    }

    cout << time - 1 << endl;
}