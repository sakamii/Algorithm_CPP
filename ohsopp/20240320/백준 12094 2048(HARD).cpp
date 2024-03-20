
#include <iostream>
using namespace std;

int i, j, n, m[21][21], ma;

bool f(int s, int tmp[][21]);

void dfs(int z, bool can, int prev, int org[][21]) {
    if (z == 11) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ma = max(ma, org[i][j]);
        return;
    }

    int x = 0, tmp[21][21];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            x = max(x, org[i][j]);

    if ((x << (11 - z)) <= ma) return;

    for (int i = 1; i <= 4; i++) {
        if (!can && i == prev) continue;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                tmp[i][j] = org[i][j];

        dfs(z + 1, f(i, tmp), i, tmp);
    }
}

bool up(int t[][21]) {
    bool ret = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0, last = -1;

        for (int j = 1; j <= n; j++) {
            if (t[j][i]) {
                if (last == t[j][i]) {
                    cnt++;
                    t[j - cnt][i] += t[j][i];
                    t[j][i] = 0;
                    last = -1;
                }
                else {
                    last = t[j][i];
                    t[j - cnt][i] = t[j][i];
                    if (cnt) t[j][i] = 0;
                }
            }
            else cnt++;
        }
        for (int j = 1; j <= n; j++)
            if (t[j][i] && t[j][i] == t[j - 1][i])
                ret = true;
    }
    return ret;
}

bool down(int t[][21]) {
    bool ret = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0, last = -1;

        for (int j = n; j; j--) {
            if (t[j][i]) {
                if (last == t[j][i]) {
                    cnt++;
                    t[j + cnt][i] += t[j][i];
                    t[j][i] = 0;
                    last = -1;
                }
                else {
                    last = t[j][i];
                    t[j + cnt][i] = t[j][i];
                    if (cnt) t[j][i] = 0;
                }
            }
            else cnt++;
        }
        for (int j = n; j; j--)
            if (t[j][i] && t[j][i] == t[j - 1][i])
                ret = true;
    }
    return ret;
}

bool left(int t[][21]) {
    bool ret = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0, last = -1;

        for (int j = 1; j <= n; j++) {
            if (t[i][j]) {
                if (last == t[i][j]) {
                    cnt++;
                    t[i][j - cnt] += t[i][j];
                    t[i][j] = 0;
                    last = -1;
                }
                else {
                    last = t[i][j];
                    t[i][j - cnt] = t[i][j];
                    if (cnt) t[i][j] = 0;
                }
            }
            else cnt++;
        }
        for (int j = 1; j <= n; j++)
            if (t[i][j] && t[i][j] == t[i][j - 1])
                ret = true;
    }
    return ret;
}

bool right(int t[][21]) {
    bool ret = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0, last = -1;

        for (int j = n; j > 0; j--) {
            if (t[i][j]) {
                if (last == t[i][j]) {
                    cnt++;
                    t[i][j + cnt] += t[i][j];
                    t[i][j] = 0;
                    last = -1;
                }
                else {
                    last = t[i][j];
                    t[i][j + cnt] = t[i][j];
                    if (cnt) t[i][j] = 0;
                }
            }
            else cnt++;
        }
        for (int j = 1; j <= n; j++)
            if (t[i][j] && t[i][j] == t[i][j - 1])
                ret = true;
    }
    return ret;
}

bool f(int s, int tmp[][21]) {
    if (s == 1)  return up(tmp);
    if (s == 2) return down(tmp);
    if (s == 3) return left(tmp);
    if (s == 4) return right(tmp);
}

int main() {
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> m[i][j];

    dfs(1, 1, 0, m);

    cout << ma;
}
