#include<iostream>
#include<vector>
using namespace std;

/*
    3차원 배열을 사용한 dfs
    % 연산자를 잘 사용하는 것이 중요
*/

vector<vector<vector<int>>> v;
int N, T, ans;
int visited[101][101];

// 우 1, 상 2, 좌 3, 하 0
int dir[13][3][3] = {
    {{0,0,0},{0,0,0}, {0,0,0}},
    {{-1,0,2},{0,1,1}, {1,0,0}},
    {{0,-1,3},{-1,0,2},{0,1,1}},
    {{-1,0,2},{0,-1,3},{1,0,0}},
    {{0,-1,3},{1,0,0}, {0, 1,1}},
    {{-1,0,2},{0,1,1},{200, 200,0}},
    {{0,-1,3},{-1,0,2},{200, 200,0}},
    {{1,0,0},{0,-1,3}, {200, 200,0}},
    {{1,0,0},{0,1,1},{200, 200,0}},
    {{0,1,1}, {1,0,0},{200, 200,0}},
    {{-1,0,2},{0,1,1}, {200, 200,0}},
    {{0,-1,3},{-1, 0,2},{200, 200,0}},
    {{1,0,0}, {0, -1,3},{200, 200,0}}
};

void dfs(int y, int x, int t, int d) {
    if (t >= T) return;

    int now = t % 4;
    int sign = v[y][x][now];

    if (sign % 4 != d) return;

    for (int i = 0; i < 3; i++) {
        int dy = y + dir[sign][i][0];
        int dx = x + dir[sign][i][1];
        int nd = dir[sign][i][2];
        if (dy >= N || dx >= N || dx < 0 || dy < 0) continue;
        if (!visited[dy][dx]) {
            visited[dy][dx] = 1;
            ans++;
        }
        dfs(dy, dx, t + 1, nd);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;

    v.resize(N, vector<vector<int>>(N, vector<int>(4)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> v[i][j][k];
            }
        }
    }

    ans = 1;
    visited[0][0] = 1;
    if (v[0][0][0] % 4 != 2) {
        cout << ans;
        return 0;
    }

    dfs(0, 0, 0, 2);

    cout << ans;

    return 0;
}
