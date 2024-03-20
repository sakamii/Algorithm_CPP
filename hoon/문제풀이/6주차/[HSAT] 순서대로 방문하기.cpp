#include <iostream>
#include <vector>
/*

n이 작으니 당연히 dfs 완탐문제.
m개의 지점을 순서대로 탐색해야하기 때문에
주어진 m개의 지점을 순서대로 벡터에 넣고
idx에 방문하면 idx를 늘려주는 식으로 dfs 탐색

*/
struct temp
{
    int y, x;
};
int n, m;
int map[5][5];

temp v[16];

int answer = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int visited[5][5];
using namespace std;

void dfs(int y, int x, int idx)
{
    if (idx == m)
    {
        answer += 1;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx] == 1)
            continue;
        if (map[ny][nx] == 1)
            continue;
        visited[ny][nx] = 1;
        if (ny == v[idx].y && nx == v[idx].x)
        {
            dfs(ny, nx, idx + 1);
        }
        else
        {
            dfs(ny, nx, idx);
        }
        visited[ny][nx] = 0;
    }
}

int main(int argc, char **argv)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].y >> v[i].x;
        v[i].y -= 1;
        v[i].x -= 1;
    }

    visited[v[0].y][v[0].x] = 1;

    dfs(v[0].y, v[0].x, 1);

    cout << answer << endl;
    return 0;
}