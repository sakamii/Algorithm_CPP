#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int n;
int map[21][21];
int answer;

/*
0 : 왼쪽으로 미는 경우
1 : 오른쪽으로 미는 경우
2 : 위로 미는 경우
3 : 아래로 미는 경우


각 경우에 대해 dfs를 수행해야하지만
dfs 수행시 map을 계속 복사를 해줘야함.

dfs 완전탐색의 의의는
그 각각의 namespace에서 현재 상태를 저장하고 있다는게 중요함.
dfs를 시작하면서 map을 복사하고,
dfs에서 탈출하는 지점에서 rotate된 map을 현 depth의 copy_map으로 돌려줘야함.
*/
void rotate(int dir)
{
    queue<int> q;
    if (dir == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            int idx = 0;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                if (map[i][idx] == 0)
                {
                    map[i][idx] = temp;
                }
                else if (map[i][idx] == temp)
                {
                    map[i][idx] *= 2;
                    idx += 1;
                }
                else
                {
                    idx += 1;
                    map[i][idx] = temp;
                }
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            int idx = n - 1;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                if (map[i][idx] == 0)
                {
                    map[i][idx] = temp;
                }
                else if (map[i][idx] == temp)
                {
                    map[i][idx] *= 2;
                    idx -= 1;
                }
                else
                {
                    idx -= 1;
                    map[i][idx] = temp;
                }
            }
        }
    }
    else if (dir == 3)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            int idx = 0;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                if (map[idx][j] == 0)
                {
                    map[idx][j] = temp;
                }
                else if (map[idx][j] == temp)
                {
                    map[idx][j] *= 2;
                    idx += 1;
                }
                else
                {
                    idx += 1;
                    map[idx][j] = temp;
                }
            }
        }
    }
    else if (dir == 4)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
            int idx = n - 1;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                if (map[idx][j] == 0)
                {
                    map[idx][j] = temp;
                }
                else if (map[idx][j] == temp)
                {
                    map[idx][j] *= 2;
                    idx -= 1;
                }
                else
                {
                    idx -= 1;
                    map[idx][j] = temp;
                }
            }
        }
    }
}

void dfs(int depth)
{
    int copy_map[21][21];
    memcpy(copy_map, map, sizeof(map));
    for (int k = 1; k <= 4; k++)
    {
        rotate(k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                answer = max(answer, map[i][j]);
            }
        }
        if (depth < 3)
        {
            dfs(depth + 1);
            memcpy(map, copy_map, sizeof(copy_map));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    dfs(0);
    cout << answer << endl;
    return 0;
}