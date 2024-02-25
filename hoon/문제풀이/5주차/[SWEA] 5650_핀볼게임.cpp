#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct info
{
    int x, y;
};
info tmp;
int map[102][102], num, result;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
// 방향별 튕기는 방향 벡터들, -1은 제자리로 돌아가는 방향 : 게임 종료 조건
int block[6][4] = {
    {0, 0, 0, 0},
    {-1, -1, 1, 0},
    {1, -1, -1, 2},
    {3, 2, -1, -1},
    {-1, 0, 3, -1},
    {-1, -1, -1, -1}};
vector<info> warmhole[11];

void game(int y, int x, int dir)
{
    int nx = x, ny = y, nd = dir, score = 0;
    while (true)
    {
        nx += dx[nd];
        ny += dy[nd];
        int next = map[ny][nx];
        if (next == 0 && score == 0)
            break;
        // 제자리로 돌아오거나 블랙홀에 빠진경우.
        if ((nx == x && ny == y) || next == -1)
        {
            result = max(result, score);
            break;
        }
        /*
        외각 벽을 5로 세팅해둔 상태이니
        1~5번 벽들만 체크해서, 튕기는 횟수 계산.
        */
        if (0 < next && next < 6)
        {
            nd = block[next][nd];
            /*
            -1인 경우에는 제자리로 돌아오는 경우니
            게임을 종료시키고 max값 갱신
            */
            if (nd == -1)
            {
                result = max(result, score * 2 + 1);
                break;
            }
            else
                score++;
        }
        /*
        웜홀 이동 조건
        웜홀은 한 쌍씩 있으니 둘이 교체해주자.
        */
        else if (next > 5)
        {
            if (nx == warmhole[next][0].x && ny == warmhole[next][0].y)
            {
                nx = warmhole[next][1].x;
                ny = warmhole[next][1].y;
            }
            else
            {
                nx = warmhole[next][0].x;
                ny = warmhole[next][0].y;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cin >> num;
        for (int i = 0; i < num + 2; i++)
        {
            map[0][i] = 5;
            map[i][0] = 5;
            map[num + 1][i] = 5;
            map[i][num + 1] = 5;
        }
        for (int i = 6; i < 11; i++)
            warmhole[i].clear();
        result = 0;

        for (int i = 1; i <= num; i++)
            for (int j = 1; j <= num; j++)
            {
                cin >> map[i][j];
                if (map[i][j] > 5)
                {
                    tmp.x = j;
                    tmp.y = i;
                    warmhole[map[i][j]].push_back(tmp);
                }
            }
        for (int i = 1; i <= num; i++)
            for (int j = 1; j <= num; j++)
            {
                if (map[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                        game(i, j, k);
                }
            }
        cout << "#" << t << " " << result << '\n';
    }
    return 0;
}