#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    완전탐색을 진행하고, 가지치기를 활용해서 해결
    k별로 한개씩 뽑고, x와 x, y와 y 각각의 길이가 가장 긴 것을
    기준으로 넓이를 계산
*/

struct node {
    int y;
    int x;
};

vector<node> v[21];
vector<node> cal;
int N, K, ans;

void dfs(int level, int large_y, int large_x, int small_y, int small_x) {
    // 아래 조건문 사용 안하면 시간초과
    // 항상 최대 길이를 찾기 때문에 정답보다 크면 range가 ans보다 크기 때문에
    // 더 찾아볼 필요가 없다.
    if (level > 1 && abs(large_y - small_y) * abs(large_x - small_x) > ans) return;
    if (level > K) {

        int range = abs(large_y - small_y) * abs(large_x - small_x);
        ans = min(ans, range);

        return;
    }

    for (int i = 0; i < v[level].size(); i++) {
        // 저장
        int ly = large_y;
        int lx = large_x;
        int sy = small_y;
        int sx = small_x;

        // 값 갱신
        if (large_y < v[level][i].y) large_y = v[level][i].y;
        if (small_y > v[level][i].y) small_y = v[level][i].y;
        if (large_x < v[level][i].x) large_x = v[level][i].x;
        if (small_x > v[level][i].x) small_x = v[level][i].x;

        dfs(level + 1, large_y, large_x, small_y, small_x);

        // 복구
        large_y = ly;
        large_x = lx;
        small_y = sy;
        small_x = sx;

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int y, x, k;
        cin >> y >> x >> k;
        v[k].push_back({ y,x });
    }

    ans = 21e8;

    dfs(1, -1001, -1001, 1001, 1001);

    cout << ans;
    return 0;
}
