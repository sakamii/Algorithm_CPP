/*
    1. ㅣ모든 농지에 대해 탐색한다.
    1.1 탐색은 먼저 한버 탐색해 갈 수 있는 방향을 queue에 넣는다.
    1.2 해당 방향 기준으로 탐색을 진행한다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define NOT_HARVEST 1000

using namespace std;

int N, M;
int map[9][9];
int harvest_map[9][9];
int dir_y[4] = { 0, -1, 0, 1 };
int dir_x[4] = { 1, 0, -1, 0 };
int dir_plus[4] = { 3, 0, 1, 2 };

void init();
int robot(int i, int j);
int robot_dir(int i, int j, int dir);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int result = 0;

        init();

        for (int i = 1; i < (N - 1); ++i) {
            for (int j = 1; j < (N - 1); ++j) {
                if (i == 3 && j == 3) {
                    cout << 2;
                }
                if (map[i][j] == 0) {
                    result = max(result, robot(i, j));
                }
            }
        }

        cout << "#" << test_case << " " << result << "\n";
    }

    return 0;
}

int robot(int y, int x) {
    int result = 0;
    for (int i = 0; i < 4; i++) {
        if (map[y + dir_y[i]][x + dir_x[i]] == 0) {
            fill(harvest_map[0], harvest_map[9], NOT_HARVEST);
            harvest_map[y][x] = 5;
            result = max(result, robot_dir(y + dir_y[i], x + dir_x[i], i));
        }
    }
    return result;
}

int robot_dir(int y, int x, int r_dir) {
    bool flag = false;
    int next_y, next_x;
    int result = 0;

    int idx = 2;
    for (int day = 2; day < M; ++day) {
        //오전
        if (harvest_map[y][x] == NOT_HARVEST) {
            for (int dir = 0; dir < 4; ++dir) {
                next_y = y + dir_y[dir];
                next_x = x + dir_x[dir];
                if (map[next_y][next_x] == 0 && (harvest_map[next_y][next_x] <= day || harvest_map[next_y][next_x] == NOT_HARVEST)) {
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                harvest_map[y][x] = day + idx + 3;
                idx++;
            }
            else continue;
        }
        else {
            result++;
            harvest_map[y][x] = NOT_HARVEST;
        }

        //오후
        for (int dir = 0; dir < 4; ++dir) {
            next_y = y + dir_y[(dir + dir_plus[r_dir]) % 4];
            next_x = x + dir_x[(dir + dir_plus[r_dir]) % 4];
            if (map[next_y][next_x] == 0 && (harvest_map[next_y][next_x] <= day || harvest_map[next_y][next_x] == NOT_HARVEST)) {
                y = next_y;
                x = next_x;
                r_dir = (dir + dir_plus[r_dir]) % 4;
                break;
            }
        }
    }
    return result;
}

void init() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
}