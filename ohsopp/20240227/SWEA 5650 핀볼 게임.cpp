
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo

/*
- 사고 과정:
dfs 탐색하면서 정해진 방향으로만 쭉 가면 시간 초과 날 것으로 예상.
10000(최대 좌표 개수) * 10000(최대 탐색 횟수) * 4(방향) * t(테스트 케이스)
=> 시간 초과 발생하는 것 확인

- 시간 단축 방법
1. 평평한 벽을 만나면 왔던 경로를 그대로 돌아가서 무조건 시작 지점에 도착한다. => 1387ms
2. 어떤 출발 지점의 다음 방향 또한 빈 곳이라면,
  종료할 때까지 부딪히는 벽의 개수는 다음 지점과 같다. => 112ms

- 종료 조건 : 블랙홀, 시작 지점 도착
(시작지점 -> 시작지점)의 두 가지 경우:
    (1) 평평한 벽을 만나서 왔던 경로를 그대로 돌아가는 경우
    (2) 사이클이 만들어지는 경우

(1) 평평한 벽을 만나면 왔던 경로를 그대로 돌아가므로,
  그전까지 부딪힌 벽의 개수를 cnt라고 한다면
  시작 지점부터 시작 지점까지 돌아갈 때 (2 * cnt + 1)개의 벽을 부딪히게 됨.
(2) 사이클이 만들어지는 경우는 지금까지 부딪힌 벽의 개수 cnt를 그대로 반환.
(3) 블랙홀을 만나는 경우 또한 지금까지 부딪힌 벽의 개수 cnt를 그대로 반환.
블랙홀을 만나는 경우는 시작 지점과 리턴값이 같으므로 시작 지점을 -1(블랙홀)로 만들어두고 진행.
*/

#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
 
int t, n, k, ans, arr[102][102];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };    // 상하좌우
vector<pii> wormholes[11];
vector<pii> starts;
 
int chgDir[5][5] = {  // 1~4번 블록을 상하좌우 방향으로 부딪힐 때 방향을 바꿔줌
    {},
    {5, 3, 0, 5},
    {3, 5, 1, 5},
    {2, 5, 5, 1},
    {5, 2, 5, 0},
};
 
void init() {
    fill(arr[1], arr[101], 0);
    starts.clear();
    for (int i = 6; i <= 10; i++)
        wormholes[i].clear();
    ans = 0;
}

int dfs(int x, int y, int dir, int cnt) {
    int nx = x + dx[dir], ny = y + dy[dir], nd = dir;
    int r = arr[nx][ny];    // r : 다음 위치의 값

    if (!cnt && !r) return 0;   // 시간 단축

    if (r == -1)        // r이 시작 지점 또는 블랙홀
        return cnt;
    else if (r == 5)    // r이 맵 테두리나 5번 블록
        return 2 * cnt + 1;

    else if (r > 0 && r < 5) {    // r이 1~4 블록
        int nd = chgDir[r][dir];
        if (nd == 5) return 2 * cnt + 1;    // 평평한 벽
        else cnt++, dir = nd;  // 대각선 벽
    }
    else if (r > 5) {    // r이 웜홀
        int nnx, nny;
        if (wormholes[r][0].first == nx && wormholes[r][0].second == ny) {
            nnx = wormholes[r][1].first;
            nny = wormholes[r][1].second;
        }
        else {
            nnx = wormholes[r][0].first;
            nny = wormholes[r][0].second;
        }
        nx = nnx, ny = nny;
    }
    return dfs(nx, ny, dir, cnt);
}
 
int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
 
        init();
        for (int i = 0; i <= n + 1; i++)
            arr[i][0] = arr[0][i] = arr[n + 1][i] = arr[i][n + 1] = 5;
 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> k;
                arr[i][j] = k;
 
                if (k > 5)    // 웜홀
                    wormholes[k].push_back({ i,j });
                else if (!k)    // 시작 지점
                    starts.push_back({ i,j });
            }
 
        for (int i = 0; i < starts.size(); i++) {
            int x = starts[i].first, y = starts[i].second;
            arr[x][y] = -1;
            for (int d = 0; d < 4; d++)
                ans = max(ans, dfs(x, y, d, 0));
            arr[x][y] = 0;
        }
        cout << "#" << tc << " " << ans << '\n';
    }
}
