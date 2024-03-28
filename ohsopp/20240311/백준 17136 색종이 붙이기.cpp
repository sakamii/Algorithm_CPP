
/*
dfs 시작할 때 브루트포스 돌면서 1을 만나면,
5X5부터 1X1까지의 색종이 중에 맞는 색종이를 붙인다.
무조건 왼쪽위의 1을 먼저 만나게 되므로 오른쪽과 아래만 1인지 확인하면 된다.

만약 x,y가 10을 넘어가면, ans값을 dfs에서의 색종이 개수인 cnt와 비교하여 갱신시킨다.
*/

#include <iostream>
using namespace std;

int v[10][10], p[6], ans = 1e5;

bool check(int x, int y, int a) {    // 색종이 aXa 크기를 붙일 수 있는지 체크
    for (int i = x; i < x + a; i++)
        for (int j = y; j < y + a; j++)
            if (!v[i][j]) return false;

    return true;
}

void change(int x, int y, int size, int k) {  // 붙일 수 있다면 붙였다고 방문처리
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            v[i][j] = k;
}

void dfs(int x, int y, int cnt) {

    if (ans <= cnt) return;

    while (!v[x][y]) {  // dfs 시작 시 1을 만날 때까지 탐색 진행
        y++;
        if (y >= 10) {
            x++;
            if (x >= 10) {
                ans = min(ans, cnt);
                return;
            }
            y = 0;
        }
    }

    for (int i = 5; i; i--) {
        if (x + i > 10 || y + i > 10 ||
            p[i] == 5 || !check(x, y, i)) continue;

        p[i]++;
        change(x, y, i, 0);

        dfs(x, y, cnt + 1);

        p[i]--;
        change(x, y, i, 1);
    }
}

int main() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> v[i][j];

    dfs(0, 0, 0);

    if (ans < 1e5) cout << ans;
    else cout << -1;
}
