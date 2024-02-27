#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

/*
    1. 각 충전기 영역을 bfs로 영역 표시
    2.
*/

struct node {
    int a;
    int b;
};

struct battery {
    int x;
    int y;
    int c;
    int p;
};

struct priority {
    int p;
    int num;
};


vector<node> v;
vector<battery> bc;
vector<int> map[11][11];
int pq[100001];
int T, N, K, M, A, ans;
int dir[5][2] = { {0,0}, {-1,0}, {0,1}, {1,0}, {0,-1} };


void bfs(int x, int y, int c, int index) {
    bool visited[11][11] = { false, };

    queue<battery> q;
    q.push({ x,y });
    map[y][x].push_back(index);
    visited[y][x] = true;

    while (true) {
        battery now = q.front();
        q.pop();

        if (c == now.c) break;

        for (int i = 1; i < 5; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];

            if (visited[dy][dx] == true) continue;
            if (dy >= 11 || dx >= 11 || dy <= 0 || dx <= 0) continue;
            visited[dy][dx] = true;
            map[dy][dx].push_back(index);
            q.push({ dx,dy,now.c + 1 });
        }
    }
}

// A와 B의 위치가 충전영역 위인 경우를 계산
void check(int x1, int y1, int x2, int y2) {

    int charge = 0;
    int c1 = 0, c2 = 0;
    int f1 = 0, f2 = 0;

    for (int i = 0; i < map[y1][x1].size(); i++) {
        f1 = map[y1][x1][i];
        c1 = pq[f1];
        for (int j = 0; j < map[y2][x2].size(); j++) {
            f2 = map[y2][x2][j];
            c2 = pq[f2];

            // A와 B가 같은 충전기 영역인 경우 해당 충전영역 값 1개만 필요
            if (f1 == f2) charge = max(charge, c1);

            // 영역이 서로 다른 경우 각 영역의 값 필요
            else charge = max(charge, c1 + c2);
        }
    }

    ans += charge;
}

// A와 B가 이동하는 코드
void move(int x1, int y1, int x2, int y2) {
    queue<battery> q;
    q.push({ x1,y1 });
    q.push({ x2,y2 });
    check(x1, y1, x2, y2);

    for (int i = 0; i < M; i++) {

        battery now_a = q.front();
        q.pop();
        battery now_b = q.front();
        q.pop();

        int dy1 = now_a.y + dir[v[i].a][0];
        int dx1 = now_a.x + dir[v[i].a][1];
        int dy2 = now_b.y + dir[v[i].b][0];
        int dx2 = now_b.x + dir[v[i].b][1];

        check(dx1, dy1, dx2, dy2);

        q.push({ dx1,dy1 });
        q.push({ dx2,dy2 });
    }


}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> M >> A;

        // map = 0인 경우는 충전기 영역이 아닌경우를 위해
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                map[i][j].push_back(0);
            }
        }

        // A의 이동경로
        for (int i = 0; i < M; i++) {
            int t;
            cin >> t;
            v.push_back({ t });
        }

        // B의 이동경로
        for (int i = 0; i < M; i++) {
            int t;
            cin >> t;
            v[i].b = t;
        }

        for (int i = 0; i < A; i++) {
            int x, y, c, p;
            cin >> x >> y >> c >> p;

            // i번째 충전기가 가지고 있는 파워 P 저장
            pq[i + 1] = p;

            // 영역표시를 하는 구간인데 i+1이라는 index를 부여해서
            // 어떤 충전기의 영역인지 표시
            bfs(x, y, c, i + 1);
        }

        move(1, 1, 10, 10);

        cout << "#" << t << " " << ans << endl;

        ans = 0;
        v.clear();
        memset(pq, 0, sizeof(pq));
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++)
                map[i][j].clear();
        }
    }

    return 0;
}
