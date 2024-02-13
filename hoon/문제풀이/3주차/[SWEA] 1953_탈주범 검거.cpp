#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int n, m, r, c, l;
int map[50][50];
bool visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<int> turner[8] = {{}, {0, 1, 2, 3}, {0, 1}, {2, 3}, {0, 3}, {1, 3}, {1, 2}, {0, 2}};
vector<int> connect[4] = {{1, 2, 5, 6}, {1, 2, 4, 7}, {1, 3, 4, 5}, {1, 3, 6, 7}};
int bfs(int time)
{
    int cnt = 1;
    visited[r][c] = true;
    queue<pair<int, int>> qu;
    qu.push({r, c});
    while (!qu.empty())
    {
        int size = qu.size();
        while (size--)
        {
            int y = qu.front().first;
            int x = qu.front().second;
            int t = map[y][x];
            qu.pop();
            for (int i = 0; i < turner[t].size(); i++)
            {
                int dir = turner[t][i];
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                {
                    if (visited[ny][nx] || map[ny][nx] == 0)
                        continue;
                    bool fail = true;
                    for (int j = 0; j < 4; j++)
                    {
                        if (connect[dir][j] == map[ny][nx])
                        {
                            fail = false;
                            break;
                        }
                    }
                    if (fail)
                        continue;
                    visited[ny][nx] = true;
                    cnt++;
                    qu.push({ny, nx});
                }
            }
        }
        time--;
        if (time == 1)
            break;
    }
    memset(visited, false, sizeof(visited));
    return cnt;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        if (l == 1)
        {
            printf("#%d 1\n", test_case);
        }
        else
        {
            printf("#%d %d\n", test_case, bfs(l));
        }
    }

    return 0;
}
