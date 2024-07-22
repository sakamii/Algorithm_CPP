#include <iostream>
using namespace std;

int N, ans, col[15];

bool isPossible(int num) {
    for (int i = 0; i < num; i++)
        if (col[num] == col[i] || abs(num - i) == abs(col[num] - col[i]))
            return false;
    return true;
}

void dfs(int idx) {
    if (idx == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[idx] = i;
        if (isPossible(idx))
            dfs(idx + 1);
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << ans;
}
