#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    보자마자 무지성 bfs로 외부 공간은 visited = 1로 처리하여 구분해줌
    가장자리는 치즈가 없기 떄문에 0,0부터  bfs과정을 진행하면 방문하는 곳은 모두 외부 공간
    위의 조건을 몰라서 맵의 크기를 +2해서 0,0 부터 bfs를 돌려 외부 공간 체크 <-- .문제를 제대로 읽자!!
    치즈가 사라졌을 때, 내부와 공간이 연결되면 한번더 bfs를 해줘야 함 <-- 이거 안해서 시간초과
    나머지는 어려운 부분 딱히 없음
*/

struct node {
    int y;
    int x;
};

queue<node> rm;
int map[102][102];
int visited[102][102];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M, ans, cnt;

// 2면을 공유하면 queue에 push
void check(int y, int x) {
    int air = 0;
    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (map[dy][dx]) continue;
        // visited가 1이면 외부 공간임
        if (visited[dy][dx]) air++;
    }

    // air : 외부와 공유하는 면의 수
    if (air >= 2) rm.push({ y,x });
}

void bfs(int y, int x) {
    queue<node> q;
    q.push({ y,x });
    visited[y][x] = 1;
    map[y][x] = 0;

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];
            if (dy > N + 1 || dx > M + 1 || dy < 0 || dx < 0 || visited[dy][dx]) continue;
            if (map[dy][dx]) continue;
            visited[dy][dx] = 1;

            q.push({ dy,dx });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            // cnt : 치즈의 갯수
            if (map[i][j]) cnt++;
        }
    }

    //외부 공간 체크
    bfs(0, 0);

    while (cnt > 0) {
        //해당 치즈가 외부공간과 2면을 공유하는지 체크
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (map[i][j]) check(i, j);
            }
        }
        // ans : 시간
        // 체크되고나서 1초 후에 치즈가 사라짐
        ans++;
        while (!rm.empty()) {
            node del = rm.front();
            rm.pop();

            // 제거되면서 내부공간과 연결되는지 확인하기 위해
            // bfs를 통해 탐색
            bfs(del.y, del.x);

            //치즈개수 - 1
            cnt--;
        }
    }

    cout << ans;

    return 0;
}
