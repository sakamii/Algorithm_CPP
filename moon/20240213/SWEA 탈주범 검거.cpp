#include<iostream>

#include<algorithm>

#include<queue>

#include<vector>
using namespace std;

struct node {
    int y;
    int x;
    int type;
    int hour;
};

int map[51][51];
int visited[51][51];
int T, N, M, R, C, L, H;
int ans, len, hour;

int dir[8][4][2] = {
    { {0,0},{0,0},{0,0},{0,0} },
    { {-1,0},{0,1},{1,0},{0,-1} },
    { {-1,0},{1,0},{0,0},{0,0} },
    { {0,1},{0,-1},{0,0},{0,0} },
    { {-1,0},{0,1},{0,0},{0,0} },
    { {1,0},{0,1},{0,0},{0,0} },
    { {1,0},{0,-1},{0,0},{0,0} },
    { {-1,0},{0,-1},{0,0},{0,0} }
};

void check(int x) {
    if (x == 1) len = 4;
    else len = 2;
}

int check_type(int to, int y, int x, int i) {
    if (i == 0) {
        if (to == 1) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6) return 0;
            else return 1;
        }
        else if (to == 2) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6) return 0;
            else return 1;
        }
        else if (to == 3) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 4) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6) return 0;
            else return 1;
        }
        else if (to == 5) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 6) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 7) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6) return 0;
            else return 1;
        }
    }
    else if (i == 1) {
        if (to == 1) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 2) {
            if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 3) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5) return 0;
            else return 1;
        }
        else if (to == 4) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 5) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7) return 0;
            else return 1;
        }
        else if (to == 6) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 5 || map[y][x] == 4) return 0;
            else return 1;
        }
        else if (to == 7) {
            if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5) return 0;
            else return 1;
        }
    }
    else if (i == 2) {
        if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7) return 0;
        else return 1;
    }
    else if (i == 3) {
        if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5) return 0;
        else return 1;
    }
    return 1;
}

void solution(int rol, int col, int h) {
    queue<node> q;
    q.push({ rol, col, map[rol][col], h });
    visited[rol][col] = 1;
    ans++;

    while (!q.empty()) {
        node now = q.front();
        q.pop();
        check(now.type);

        if (now.hour == L) return;

        for (int i = 0; i < len; i++) {
            int dy = now.y + dir[now.type][i][0];
            int dx = now.x + dir[now.type][i][1];
            if (dy >= N || dx >= M || dy < 0 || dx < 0) continue;
            if (map[dy][dx] == 0) continue;
            if (visited[dy][dx] == 1) continue;
            if (check_type(now.type, dy, dx, i) == 1) continue;
            visited[dy][dx] = 1;
            ans++;;
            q.push({ dy, dx, map[dy][dx],now.hour + 1 });
        }
    }
}

void input(int x) {

    cin >> N >> M >> R >> C >> L;
    ans = 0; H = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }
}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input(0);

        solution(R, C, H);

        cout << "#" << t << " " << ans << endl;

    }


    return 0;
}
