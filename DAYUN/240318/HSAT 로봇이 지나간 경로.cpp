/*
    IDEA :
        1. 시작점 찾기
        1.1 홀수이면 무조건 시작점(한붓그리기)
        1.2 짝수이면 어디든 시작점이 될 수 있다.
        1.2.1 짝수이면 왼쪽 위에서 시작
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct save_point
{
    int y;
    int x;
    int dir;
};

int h, w;
int a, b;
int map[25][25];
// 방향
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
// 원래 방향에서 왼쪽으로 갈 경우
int left_dir[] = { 2, 3, 1, 0 };
// 원래 방향에서 왼쪽길이 없을 때, 오른쪽으로 간 경우 (오른쪽 2번 회전)
int right_dir[] = { 1, 0, 3, 2 };

//모든 길을 지나갔는지 확인
int num_route = 0;
//루트 저장하는 배열
char cmd[1000];

//처음 방향 Print하기 위한 변수
char dir_char[] = { '^', 'v', '<', '>' };

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                map[i][j] = 0;
            else
            {
                num_route++;
                map[i][j] = 1;
            }
        }
    }

    //연결이 홀수인 게 하나도 없을 경우, a == -1
    a = -1, b = -1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int link = 0;
            if (map[i][j])
            {
                for (int d = 0; d < 4; d++)
                {
                    int nexti = ydir[d] + i;
                    int nextj = xdir[d] + j;
                    if ((nexti >= 0) && (nexti < h) && (nextj >= 0) && (nextj < w))
                    {
                        if (map[nexti][nextj])
                            link++;
                    }
                }

                // 홀수이면 바로 시작점으로 설정
                if (link % 2)
                {
                    a = i;
                    b = j;
                    i = h;
                    break;
                }
            }
        }
    }
    // 모든 꼭짓점이 짝수이면 왼쪽 위
    if (a == -1)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j])
                {
                    a = i;
                    b = j;
                    i = h;
                    break;
                }
            }
        }
    }

    //시작지점 Print
    cout << a + 1 << " " << b + 1 << "\n";
    map[a][b] = 0;


    // 처음 갈 수 있는 방향 
    int dir = 0;
    for (int d = 0; d < 4; d++)
    {
        int nexti = ydir[d] + a;
        int nextj = xdir[d] + b;
        if (map[nexti][nextj])
        {
            dir = d;
            break;
        }
    }
    //출발 방향 Print
    cout << dir_char[dir] << "\n";

    int cmd_idx = 0;
    //왼쪽으로 회전 후, 갈 수 없으면 오른쪽으로 회전
    //전에 왼쪽으로 회전했는지 확인하기 위한 변수
    bool leftflag = true;
    //처음 시작지점 빼기
    num_route--;

    //길 시작
    while (num_route > 0)
    {
        // 직진
        int next_y = ydir[dir];
        int next_x = xdir[dir];
        if ((next_y * 2 + a < h) && (next_y * 2 + a >= 0) && (next_x * 2 + b < w) && (next_x * 2 + b >= 0))
        {
            if (map[next_y + a][next_x + b] && map[next_y * 2 + a][next_x * 2 + b])
            {
                //방문처리, 직진 했다고 기록, 남은 route줄이기, 다시 회전하게 된다면 왼쪽회전으로 
                map[next_y * 2 + a][next_x * 2 + b] = 0;
                map[next_y + a][next_x + b] = 0;
                a += next_y * 2;
                b += next_x * 2;
                cmd[cmd_idx++] = 'A';
                num_route -= 2;
                leftflag = true;
                continue;
            }
        }
        //왼쪽 회전
        if (leftflag) {
            dir = left_dir[dir];
            leftflag = false;
            cmd[cmd_idx++] = 'L';
        }
        //오른 쪽 회전
        else {
            dir = right_dir[dir];
            //전에 왼쪽 회전의 길이 없었으므로 cmd_idx - 1로 'L'을 'R'로 변경
            cmd[cmd_idx - 1] = 'R';
        }
    }

    for (int i = 0; i < cmd_idx; i++) {
        cout << cmd[i];
    }
}