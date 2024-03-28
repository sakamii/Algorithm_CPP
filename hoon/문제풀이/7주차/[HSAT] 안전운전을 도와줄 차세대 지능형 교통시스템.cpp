#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

/*
각 신호에 대해 차량이 갈수있는 경우가 제한되어있던 문제
그러나 문제에서 차량이 진입하는 방향과 도착지점에서 켜질 신호의 방향이 일치해야 한다는 점이 중요함
그래서 각 신호의 첫번째 인덱스는 직진하는 방향으로 지정해줌.
또한 방문했던곳을 재방문해서 다른곳으로 방문해도 되기 때문에
visited는 필요가 없음.

그래서 queue에 들어있는 size만큼(특정 시간대에 방문가능한 교차로지점) bfs를 돌리고
그걸 t시간만큼 반복하면 정답.



*/
int n, T;
int map[101][101][4];
int visited[101][101];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
set<pair<int, int>> result;
vector<int> signals[13] = {
    {},
    {0, 1, 3},
    {1, 0, 2},
    {2, 1, 3},
    {3, 0, 2},
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 0},
    {0, 3},
    {1, 0},
    {2, 1},
    {3, 2}};

struct prev_info
{
    int y, x, dir;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int z = 0; z < 4; z++)
            {
                cin >> map[i][j][z];
            }
        }
    }
    int cnt = 1;
    queue<prev_info> q;
    visited[0][0] = 1;
    result.insert({0, 0});
    q.push({0, 0, 1});
    int t = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (t == T)
            break;
        while (size--)
        {
            int cy = q.front().y;
            int cx = q.front().x;
            int prev_dir = q.front().dir;
            int ctime = t % 4;
            int csign = map[cy][cx][ctime];
            q.pop();
            if (prev_dir != signals[csign][0])
                continue;
            for (int i = 0; i < signals[csign].size(); i++)
            {
                int ny = cy + dy[signals[csign][i]];
                int nx = cx + dx[signals[csign][i]];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                    continue;
                result.insert({ny, nx});
                prev_info temp;
                q.push({ny, nx, signals[csign][i]});
            }
        }
        t += 1;
    }

    cout << result.size() << endl;
}