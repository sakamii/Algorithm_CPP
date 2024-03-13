#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

/*
    이동 길이가 2로 고정되어 있기 때문에 
    시작 좌표 또는 끝 좌표를 찾을 수 있다는 것을 알아야함.
    시작 좌표에서 부터 탐색을 시작하면 무조건 최단 경로가 된다.
*/

vector<char> v;
char map[30][30];
int H, W, ans, cnt;
int visited[30][30];
int dir[4][2] = { {-2,0},{0,2},{2,0},{0,-2} };
int dir2[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

// 시작좌표를 찾는 코드
int check(int y, int x) {

    int k = 0;
    for (int i = 0; i < 4; i++) {
        int dy = y + dir2[i][0];
        int dx = x + dir2[i][1];
        if (dy > H || dx > W || dy <= 0 || dx <= 0) continue;
        if (map[dy][dx] == '#') k++;
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;


    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> map[i][j];
            if (map[i][j] == '#') cnt++;
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (map[i][j] == '#') {
                // flag == 1 이라면 시작좌표라는 뜻
                int flag = check(i, j);

                // nowd : 현재 방향
                int nowd = 0;
                if (flag == 1) {
                    cout << i << " " << j << "\n";
                    for (int t = 0; t < 4; t++) {
                        int dy = i + dir2[t][0];
                        int dx = j + dir2[t][1];
                        if (dy > H || dx > W || dy <= 0 || dx <= 0) continue;
                        if (map[dy][dx] == '#') {
                            v.push_back('0' + t);
                            nowd = t;
                        }
                    }

                    visited[i][j] = 1;
                    cnt--;
                    while (cnt > 0) {
                        int d = nowd;
                        for (int t = 0; t < 4; t++) {
                            if (d > 3) d = 0;
                            int dy = i + dir2[d][0];
                            int dx = j + dir2[d][1];
                            int dy2 = i + dir[d][0];
                            int dx2 = j + dir[d][1];
                            d++;
                            if (dy > H || dx > W || dy <= 0 || dx <= 0) continue;
                            if (visited[dy][dx]) continue;
                            if (map[dy][dx] == '.') continue;
                            if (dy2 > H || dx2 > W || dy2 <= 0 || dx2 <= 0) continue;
                            if (visited[dy2][dx2]) continue;
                            if (map[dy2][dx2] == '.') continue;

                            i = dy2;
                            j = dx2;

                            cnt -= 2;
                            nowd = d - 1;
                            visited[dy][dx] = 1;
                            if (t == 1) v.push_back('R');
                            else if (t == 2) {
                                v.push_back('R');
                                v.push_back('R');
                            }
                            else if (t == 3) v.push_back('L');
                            v.push_back('A');
                            break;
                        }
                    }

                    if (cnt == 0) {
                        if (v[0] == '0') cout << "^\n";
                        else if (v[0] == '1') cout << ">\n";
                        else if (v[0] == '2') cout << "v\n";
                        else if (v[0] == '3') cout << "<\n";
                        for (int t = 1; t < v.size(); t++) {
                            cout << v[t];
                        }
                        return 0;
                    }
                }
            }
        }
    }



    return 0;
}
