#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int map[15][20];
vector<int> v;
int n, m;

void dfs(int result, int visited);
int min_result;

int main(int argc, char** argv)
{
    cin >> n >> m;
    v.resize(n);
    min_result = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'a') map[i][j] = 0;
            else if (ch == 'c') map[i][j] = 1;
            else if (ch == 'g') map[i][j] = 2;
            else if (ch == 't') map[i][j] = 3;
            else map[i][j] = -1;
        }
    }

    for (int i = (1 << n) - 1; i >= 0; i--) {
        bool flag = true;
        int s[20];
        memset(s, -1, sizeof(int) * m);
        for (int j = 0; j < n; j++) {
            if (((i >> j) & 1) == 0) {
                continue;
            }
            for (int k = 0; k < m; k++) {
                if (map[j][k] == -1 || map[j][k] == s[k]) continue;
                if (s[k] == -1) {
                    s[k] = map[j][k];
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            for (int k = 0; k < v.size(); k++) {
                if ((v[k] & i) == v[k]) {
                    flag = false;
                    break;
                }
                else if ((v[k] & i) == i) {
                    flag = false;
                    v[k] = i;
                    break;
                }
            }
            if (flag) {
                v.push_back(flag);
            }
        }

    }

    dfs(0, 0);
    cout << min_result;
    return 0;
}

void dfs(int result, int visited) {
    if (result >= min_result) return;

    int i;

    for (i = 0; i <= n; i++) {
        if (!((visited >> i) & 1)) {
            break;
        }
    }

    if (i == n) {
        min_result = result;
        return;
    }

    for (int j : v) {
        if ((j >> i) & 1) {
            dfs(result + 1, visited | j);
        }
    }
}