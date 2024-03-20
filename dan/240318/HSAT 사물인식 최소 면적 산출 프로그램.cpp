#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, ans;
int smally = 1000, smallx = 1000, bigy = -1000, bigx = -1000;
vector<vector<pair<int, int>>>colors;

void dfs(int level, int sy, int sx, int by, int bx);

int main(int argc, char** argv)
{
    cin >> n >> k;
    colors.resize(k + 1);
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        smally = min(smally, a);
        smallx = min(smallx, b);
        bigy = max(bigy, a);
        bigx = max(bigx, b);
        colors[c].push_back({ a, b });
    }
    ans = abs(bigy - smally) * abs(bigx - smallx);
    int de = -1;
    dfs(1,1000,1000,-1000,-1000);
    cout << ans;
    return 0;
}

void dfs(int level, int sy, int sx, int by, int bx) {
    // 다 하나씩 들어왔을때 크기 비교해야됨
    if (level == k+1) {
        ans = min(ans, abs(by - sy) * abs(bx - sx));
        return;
    }
    // 새로 만든 직사각형이 원래보다 크면 안됨

    for (int i = 0; i < colors[level].size(); i++) {
        int ny = colors[level][i].second;
        int nx = colors[level][i].first;
        int tsy = min(sy, ny);
        int tsx = min(sx, nx);
        int tby = max(by, ny);
        int tbx = max(bx, nx);
        if (ans <= (abs(tsy - tby) * abs(tbx - tsx)))continue;
        dfs(level + 1,tsy, tsx, tby, tbx);
    }
}
