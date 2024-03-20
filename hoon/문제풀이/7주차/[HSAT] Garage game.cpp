#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

/*

 테트리스 느낌의 게임을 진행할건데
 가지치기를 하지 않으면 안된다

 문제에서 총 3번의 dfs를 요구하는데
 3번 모두를 채울 양의 대기열이 있으니 비어있는 경우는 생각 X

 문제 조건을 위해 gravity와 wait queue를 down 시켜야 하는데
 이부분을 queue을 통해 해결했음.
 => 이부분을 최적화해야 시간초과가 안날거라 생각했지만 이게 아니었음.

1. bfs를 하면서 습관적으로 visited를 초기화함
=> 이문제에서도 그럼
=> dfs이후에 bfs를 진행해야하는데, visited를 습관적으로 초기화하게 됨
=> 이러면 map을 복사해놓고 다시 돌아오면서 visited가 풀리게 되고
=> 또한번 현재 number와 일치하는지 연산을 돌리고, visited를 체크하는 과정을 겪게됨
=> 이미 방문했던 number에 대해서 다시한번 visited를 채우는꼴
=> 그래서 visited 초기화는 의미 X

2. dfs를 진행하면서 습관적으로 필요없는 부분까지 맵을 복사하는 경우가 생기는데
 => 이 문제에서는 dfs가 2->3으로 넘어가는 시점에서 생김
 => dfs 의 level이 3이 되는 경우는 return처리를 하기 때문에 탐색을 하지 않음
 => 또, return이 되고 빠져나온다고 해도, 이미 3번의 dfs를 하면서 가능한 모든 지점이 방문처리 되어있기 때문에
 => 따로 map을 초기화서 재탐색을 할필요가 없음
 이 부분을 잘 해결해야함.
 => 그래서 dfs level이 2인 경우는 map을 초기화시켜주지 않으면 시간초과 안나옴.

*/
int n;
int answer = 0;
int map[45][15];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
void dfs(int cnt, int score)
{
    if (cnt == 3)
    {
        answer = max(answer, score);
        return;
    }
    bool visited[15][15] = {
        false,
    };
    int copy_map[45][15];
    for (int i = 0; i < 3 * n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            copy_map[i][j] = map[i][j];
        }
    }
    for (int i = 2 * n; i < 3 * n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int current = map[i][j];
            if (current == 0 || visited[i - 2 * n][j])
                continue;

            int num = 0;
            int min_x = j, max_x = j, min_y = i, max_y = i;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i - 2 * n][j] = true;
            while (!q.empty())
            {
                int cy = q.front().first;
                int cx = q.front().second;
                q.pop();
                map[cy][cx] = 0;
                num++;
                min_x = min(min_x, cx);
                max_x = max(max_x, cx);
                min_y = min(min_y, cy);
                max_y = max(max_y, cy);
                for (int k = 0; k < 4; k++)
                {
                    int ny = cy + dy[k];
                    int nx = cx + dx[k];
                    if (ny < 2 * n || nx < 0 || ny >= 3 * n || nx >= n)
                        continue;
                    if (visited[ny - 2 * n][nx])
                        continue;
                    if (map[ny][nx] != current)
                        continue;
                    visited[ny - 2 * n][nx] = true;
                    q.push({ny, nx});
                }
            }
            int temp = score;
            temp += num + (max_x - min_x + 1) * (max_y - min_y + 1);
            if (cnt < 2)
            {
                for (int x = 0; x < n; x++)
                {
                    queue<int> tq;
                    for (int y = 3 * n - 1; y >= 0; y--)
                    {
                        if (map[y][x] != 0)
                        {
                            tq.push(map[y][x]);
                            map[y][x] = 0;
                            if (tq.size() == n)
                                break;
                        }
                    }
                    for (int y = 3 * n - 1; y >= 2 * n; y--)
                    {
                        map[y][x] = tq.front();
                        tq.pop();
                    }
                }
                dfs(cnt + 1, temp);
                for (int y = 0; y < 3 * n; y++)
                {
                    for (int x = 0; x < n; x++)
                    {
                        map[y][x] = copy_map[y][x];
                    }
                }
            }
            else
            {
                dfs(cnt + 1, temp);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < 3 * n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    dfs(0, 0);
    cout << answer;
    return 0;
}