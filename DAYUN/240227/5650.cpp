//SWEA 5650 핀볼게임
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int n;
int map[102][102];
//상하좌우
int ydir[4] = { -1, 1, 0, 0 };
int xdir[4] = { 0, 0, -1, 1 };
// direction map[i][j] :  j방향으로 갈떄, i(블록번호)를 마주치게 된다면 바뀌는 방향
int direction_map[6][4] = {
    {0, 1, 2, 3}, //상하좌우
    {1, 3, 0, 2}, //하우상좌
    {3, 0, 1, 2}, //우상하좌
    {2, 0, 3, 1}, //좌상우하
    {1, 2, 3, 0}, //하좌우상
    {1, 0, 3, 2}  //하상우좌
};
int wormhole[5][4];
int cnt = 0;

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
        fill(&wormhole[0][0], &wormhole[4][5], -1);
        //벽을 모두 5로 바꾸기
        for (int i = 0; i <= (n + 1); i++) {
            map[i][0] = 5;
            map[0][i] = 5;
            map[n + 1][i] = 5;
            map[i][n + 1] = 5;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
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
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if((map[i][j] <= 0) || (map[i][j] > 5)) continue;
                for (int dir = 0; dir < 4; dir++) {
                    if(map[i+ ydir[dir]][j + xdir[dir]] == 0) {
                        result = max(result, run(i+ ydir[dir], j + xdir[dir], direction_map[5][dir]));
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
    int i = y;
    int j = x;

    while(true) {
        //방향으로 한칸 간다
        i += ydir[dir];
        j += xdir[dir];
        //방향 바뀐지 확인
        int block = map[i][j];

        if(((i == y) && (j == x)) || (block == -1)) {
            break;
        }

        if((block != 0) && (block <= 5)) {
            dir = direction_map[block][dir];
            result++;
        }
        else if(block > 5) {
            if ((i == wormhole[block - 6][0]) && (j == wormhole[block - 6][1])) {
                // cout << i << "," << j << " ";
                i = wormhole[block - 6][2];
                j = wormhole[block - 6][3];
            }
            else {
                i = wormhole[block - 6][0];
                j = wormhole[block - 6][1];
            }
        } 
    }
    return result;
}