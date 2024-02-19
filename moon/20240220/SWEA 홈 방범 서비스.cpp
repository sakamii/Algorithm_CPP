#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

/*
    최대 K의 크기를 해결하지 못해 결국 도움 받은 문제
    문제는 시작 좌표 부터 거리 K만큼 떨어진 곳까지 주변을 탐색하는
    유형이기 때문에 bfs를 사용
*/

struct node {
    int y;
    int x;
    int r;
};

int map[30][30];
int visited[30][30];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int T, N, M, K, ans, sum, cnt;


void solution(int y, int x, int len) {
    queue<node> q;
    q.push({ y,x,len });
    visited[y][x] = 1;
    if (map[y][x] == 1) cnt++;
    sum = 1;

    if (cnt * M - sum >= 0) ans = max(ans, cnt);

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        if (now.r == K) break;

        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy >= N || dx >= N || dy < 0 || dx < 0) continue;
            if (visited[dy][dx] == 1) continue;
            if (map[dy][dx] == 1) cnt++;
            visited[dy][dx] = 1;

            sum = (now.r + 1) * (now.r + 1) + (now.r) * (now.r);
            if (cnt * M - sum >= 0) ans = max(ans, cnt);

            q.push({ dy, dx, now.r + 1 });
        }
    }
}

void input() {

    cin >> N >> M;

    ans = 0; K = N + 1;

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


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cnt = 0;
                solution(i, j, 1);
                memset(visited, 0, sizeof(visited));
            }
        }



        cout << "#" << t << " " << ans << endl;

    }


    return 0;
}
