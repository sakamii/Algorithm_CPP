//SWEA 5650 핀볼게임

/*
    문제 읽기
    빈 공간에서만 돌리기
    최대값 구하기
    벽이나 블록에 부딪힐 때
*/
/*
    요구한 대로 구현
    모두 돌아다니면서 check
    공이 지나쳐간 자리,방향는 check 안함 : visited
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int map[100][100];
bool visited[100][100][4] = { false };
//상하좌우
int ydir[4] = { -1, 1, 0, 0 };
int xdir[4] = { 0, 0, -1, 1 };
// direction map[i][j] :  j방향으로 갈떄, i(블록번호)를 마주치게 된다면 바뀌는 방향
int direction_map[6][4] = {
    {0, 1, 2, 3}, //상하좌우
    {1, 3, 0, 2}, //하우상좌
    {3, 0, 1, 2}, //우상하좌
    {2, 0, 3 ,1}, //좌상우하
    {1, 2, 3, 0}, //하좌우상
    {1, 0, 3, 2}  //하상우좌
};
int wormhole[5][4];

int run(int y, int x, int dir);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;
        cin >> n;
        memset(wormhole, -1, sizeof(wormhole));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
                if (map[i][j] != 0) {
                    memset(visited[i][j], true, 4);
                }
                else {
                    memset(visited[i][j], false, 4);
                }
                if (map[i][j] > 5) {
                    int hole_num = map[i][j] - 6;
                    if (wormhole[hole_num][0] != -1) {
                        wormhole[hole_num][2] = i;
                        wormhole[hole_num][3] = j;
                    }
                    else {
                        wormhole[hole_num][0] = i;
                        wormhole[hole_num][1] = j;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // cout << cnt++;
            for (int j = 0; j < n; j++) {
                // cout << cnt++;
                for (int dir = 0; dir < 4; dir++) {
                    if (!visited[i][j][dir]) {
                        result = max(result, run(i, j, dir));
                        // cout << result << " ";
                    }
                }
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}

int run(int y, int x, int dir) {
    int result = 0;
    int i = x;
    int j= y;
    do {
        //벽에 부딪힌 경우
        //if(flag) cout << i << j << " ";

        i += ydir[dir];
        j += xdir[dir];
        //cout << i << j << dir << " ";


        if ((i < 0) || (i >= n) || (j < 0) || (j >= n)) {
            result++;
            //5번 블록은 모두 반대방향
            dir = direction_map[5][dir];
            i += ydir[dir];
            j += xdir[dir];
            continue;
        }
        else {
            int m = map[i][j];
            if (m == -1) return result;
            else if (m > 5) {
                if (i == wormhole[m - 6][0]) {
                    i = wormhole[m - 6][2];
                    j = wormhole[m - 6][3];
                }
                else {
                    i = wormhole[m - 6][0];
                    j = wormhole[m - 6][1];
                }
            }
            else {
                dir = direction_map[m][dir];
            }
        }
        visited[i][j][dir] = true;


    } while ((i != y) || (j != x));

    return result;
}