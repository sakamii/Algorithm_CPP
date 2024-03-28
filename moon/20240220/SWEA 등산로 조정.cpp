#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

/*
    큰 봉우리에서 작은 봉우리로만 이동이 가능하기 때문에
    BFS로 탐색하면 문제를 해결 할 수 있다고 생각함.
    하지만 K를 처리할 방법이 떠오르지 않아 (0,0) ~(N-1,N-1)까지
    모두 하나씩 줄여가면서 문제를 해결 --> N이 조금이라 컸으면 불가능
*/

struct node {
    int y;
    int x;
    int r;
};

vector<node> v;
int map[10][10];
int visited[10][10];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int T, N, K, ans, length;


void solution(int y, int x, int len) {

    ans = max(ans, len);

    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy >= N || dx >= N || dy < 0 || dx < 0) continue;
        if (map[dy][dx] >= map[y][x]) continue;
        if (visited[dy][dx] == 1) continue;
        visited[dy][dx] = 1;
        solution(dy, dx, len + 1);
        visited[dy][dx] = 0;
    }



}

void input() {

    cin >> N >> K;

    ans = 0;
    int max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] > max) {
                max = map[i][j];
                v.clear();
                v.push_back({ i,j,1 });
            }
            else if (map[i][j] == max) {
                v.push_back({ i,j,1 });
            }
        }
    }
}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input();

        for (int z = 0; z <= K; z++) {
            for (int k = 0; k < N; k++) {
                for (int j = 0; j < N; j++) {
                    map[k][j] -= z;
                    for (int i = 0; i < v.size(); i++) {
                        solution(v[i].y, v[i].x, v[i].r);
                        memset(visited, 0, sizeof(visited));
                    }
                    map[k][j] += z;
                }
            }
        }

        cout << "#" << t << " " << ans << endl;

        v.clear();
    }


    return 0;
}
