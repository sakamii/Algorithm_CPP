#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

/*
    경우의수 4가지 반복 횟수 5번
    4^5 만큼의 시간이 걸림
    단순한게 완전탐색으로 구할 수 있다.
*/

int map[30][30];
int N, ans;

// 좌 우 상 하
void move(int dir) {
    if (dir == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (map[i][j] == 0) continue;
                for (int k = j + 1; k < N; k++) {
                    if (map[i][k] == 0) continue;
                    if (map[i][k] == map[i][j]) {
                        map[i][k] = 0;
                        map[i][j] *= 2;
                    }
                    break;
                }
            }

            queue<int> q;
            int idx = 0;

            for (int j = 0; j < N; j++) {
                if (map[i][j] > 0) q.push(map[i][j]);
                map[i][j] = 0;
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                map[i][idx++] = now;
            }
        }
    }

    else if (dir == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j > 0; j--) {
                if (map[i][j] == 0) continue;
                for (int k = j - 1; k > -1; k--) {
                    if (map[i][k] == 0) continue;
                    if (map[i][k] == map[i][j]) {
                        map[i][k] = 0;
                        map[i][j] *= 2;
                    }
                    break;
                }
            }

            queue<int> q;
            int idx = N - 1;

            for (int j = N-1; j > -1; j--) {
                if (map[i][j] > 0) q.push(map[i][j]);
                map[i][j] = 0;
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                map[i][idx--] = now;
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (map[j][i] == 0) continue;
                for (int k = j + 1; k < N; k++) {
                    if (map[k][i] == 0) continue;
                    if (map[k][i] == map[j][i]) {
                        map[k][i] = 0;
                        map[j][i] *= 2;
                    }
                    break;
                }
            }

            queue<int> q;
            int idx = 0;

            for (int j = 0; j < N; j++) {
                if (map[j][i] > 0) q.push(map[j][i]);
                map[j][i] = 0;
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                map[idx++][i] = now;
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j > 0; j--) {
                if (map[j][i] == 0) continue;
                for (int k = j - 1; k > -1; k--) {
                    if (map[k][i] == 0) continue;
                    if (map[k][i] == map[j][i]) {
                        map[k][i] = 0;
                        map[j][i] *= 2;
                    }
                    break;
                }
            }

            queue<int> q;
            int idx = N - 1;

            for (int j = N; j > -1; j--) {
                if (map[j][i] > 0) q.push(map[j][i]);
                map[j][i] = 0;
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                map[idx--][i] = now;
            }
        }
    }

}

void back(int level) {
    if (level >= 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans = max(ans, map[i][j]);
            }
        }
        return;
    }

    int cp_map[30][30] = { 0, };
    memcpy(cp_map, map, sizeof(map));

    for (int i = 0; i < 4; i++) {

        move(i);

        back(level + 1);

        memcpy(map, cp_map, sizeof(cp_map));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    back(0);

    cout << ans;

    return 0;
}
