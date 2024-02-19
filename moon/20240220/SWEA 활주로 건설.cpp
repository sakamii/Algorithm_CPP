#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/*
    각 열 혹은 행 끼리의 값만 중요하기 때문에 
    bfs, dfs는 아닐거라 생각하고 접근
    무슨 알고리즘 일까 생각하면서 일단 코드를 작성하다 보니
    단순 구현 문제라는 것을 알게 되었고, 조건문을 통해 해결
    col, row를 각각 나누어서 진행
    cnt는 변화하는 지점 뒤쪽 길이, len은 변화하는 지점 앞쪽 길이
*/

int map[30][30];
int visited[30][30];
int T, N, X, ans;

void check_row(int idx) {

    int len = 1;
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (map[idx][i] == map[idx][i + 1]) {
            cnt--;
            len++;
        }
        else if (abs(map[idx][i] - map[idx][i + 1]) > 1) return;
        else if (abs(map[idx][i] - map[idx][i + 1]) == 1) {
            if (map[idx][i] > map[idx][i + 1]) {
                if (cnt > 0) return;
                else {
                    cnt = X - 1;
                    len = -X + 1;
                }
            }
            else if (map[idx][i] < map[idx][i + 1]) {
                if (len < X) return;
                else len = 1;
            }
        }
    }

    if (cnt < 1) ans++;
}

void check_col(int idx) {

    int len = 1;
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (map[i][idx] == map[i + 1][idx]) {
            cnt--;
            len++;
        }
        else if (abs(map[i][idx] - map[i + 1][idx]) > 1) return;
        else if (abs(map[i][idx] - map[i + 1][idx]) == 1) {
            if (map[i][idx] > map[i + 1][idx]) {
                if (cnt > 0) return;
                else {
                    cnt = X - 1;
                    len = -X + 1;
                }
            }
            else if (map[i][idx] < map[i + 1][idx]) {
                if (len < X) return;
                else len = 1;
            }
        }
    }

    if (cnt < 1) ans++;
}

void solution() {

    for (int i = 0; i < N; i++) {
        check_row(i);
        check_col(i);
    }

}

void input() {

    cin >> N >> X;

    ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input();

        solution();

        cout << "#" << t << " " << ans << endl;

    }


    return 0;
}
