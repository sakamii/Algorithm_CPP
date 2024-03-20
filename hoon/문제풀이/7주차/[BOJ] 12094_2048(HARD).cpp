#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, answer;
int map[21][21];

/*
0 : 우 -> 왼
1 : 왼 -> 오
2 : 아래 -> 위
3 : 위 -> 아래

풀이 전체가 EASY버전이랑 똑같음
다만, depth가 10으로 늘어났으니 가지치기를 해야함
예시로 주어진 인풋을 보면

2 2 2
4 4 4
8 8 8

EASY버전에서도 사실 여기서 한번만 이동시켜도 최댓값인 16이 도출됨 .
그러나, 완전탐색 때문에 5번까지 dfs를 호출해서 값을 찾음
=> 불필요한 연산
또한, 위 예시에서 상, 하의 움직임은 map에 어떠한 변화도 주지 않으니
이 방향으로 dfs탐색은 의미가 없음 => 불필요한 연산

따라서 위 두가지 케이스를 가지치기 하자.
1. 현재 최대값에서 만들수 있는 최대 기댓값을 구해보자
=> 현대최대값 * (2 ** 남은횟수) -> 이걸로 하면 통과함
=> 더 줄이는 방법 없을까?

2. map이 더이상 변하지 않으면 dfs 호출 X
*/
int rotate(int dir)
{
    queue<int> q;
    int maxi = -1;
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
                    maxi = max(maxi, map[i][idx]);
                }
                else if (map[i][idx] == temp)
                {
                    map[i][idx] *= 2;
                    maxi = max(maxi, map[i][idx]);
                    idx += 1;
                }
                else
                {
                    idx += 1;
                    map[i][idx] = temp;
                    maxi = max(maxi, map[i][idx]);
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
                    maxi = max(maxi, map[i][idx]);
                }
                else if (map[i][idx] == temp)
                {
                    map[i][idx] *= 2;
                    maxi = max(maxi, map[i][idx]);
                    idx -= 1;
                }
                else
                {
                    idx -= 1;
                    map[i][idx] = temp;
                    maxi = max(maxi, map[i][idx]);
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
                    maxi = max(maxi, map[idx][j]);
                }
                else if (map[idx][j] == temp)
                {
                    map[idx][j] *= 2;
                    maxi = max(maxi, map[idx][j]);
                    idx += 1;
                }
                else
                {
                    idx += 1;
                    map[idx][j] = temp;
                    maxi = max(maxi, map[idx][j]);
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
                    maxi = max(maxi, map[idx][j]);
                }
                else if (map[idx][j] == temp)
                {
                    map[idx][j] *= 2;
                    maxi = max(maxi, map[idx][j]);
                    idx -= 1;
                }
                else
                {
                    idx -= 1;
                    map[idx][j] = temp;
                    maxi = max(maxi, map[idx][j]);
                }
            }
        }
    }
    return maxi;
}

bool check(int check_map[][21])
{
    int maxi = -1;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxi = max(maxi, map[i][j]);
            if (check_map[i][j] != map[i][j])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    return flag;
}

void dfs(int depth)
{
    if (depth == 10)
        return;
    int copy_map[21][21];
    memcpy(copy_map, map, sizeof(map));
    for (int k = 1; k <= 4; k++)
    {
        int current_maxi = rotate(k);
        answer = max(answer, current_maxi);
        int expected = current_maxi * (1 << (9 - depth));
        if (check(copy_map) && answer < expected)
        {
            // cout << k << " " << depth << endl;
            //  cout << (1 << (9 - depth)) << endl;
            dfs(depth + 1);
        }
        memcpy(map, copy_map, sizeof(copy_map));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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