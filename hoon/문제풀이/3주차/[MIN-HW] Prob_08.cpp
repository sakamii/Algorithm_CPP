#include <iostream>
#include <algorithm>
#define INF 200000001

using namespace std;

int N, M, K, ans = INF;
int state[19], switches[19][9];

void dfs(int idx, int cnt) {
    if (idx == M) {
        for(int i=0; i<N; i++){
            if(state[i] == 0) return;
        }
        ans = min(ans, cnt);
        return;
    }

    dfs(idx + 1, cnt);

    for (int i = 0; i < K; i++) {
        state[switches[idx][i]] ^= 1;
    }
    dfs(idx + 1, cnt + 1);
    for (int i = 0; i < K; i++) {
        state[switches[idx][i]] ^= 1;
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> state[i];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> switches[i][j];
            switches[i][j] -= 1;
        }
    }

    dfs(0, 0);

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}