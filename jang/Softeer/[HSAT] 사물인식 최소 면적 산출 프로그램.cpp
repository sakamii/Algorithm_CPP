#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, K, a, b, c, answer = 2e9;
vector<pair<int, int>>color[22];

void cal(int nowColor, int nminx, int nminy, int nmaxx, int nmaxy) {
    for (int i = 0; i < color[nowColor].size(); i++) {
        int x1, x2, y1, y2;
        x1 = min(nminx, color[nowColor][i].first);
        x2 = max(nmaxx, color[nowColor][i].first);
        y1 = min(nminy, color[nowColor][i].second);
        y2 = max(nmaxy, color[nowColor][i].second);
        if ((x2 - x1) * (y2 - y1) < answer) {
            if (nowColor + 1 == K + 1) {
                answer = (x2 - x1) * (y2 - y1);
            }
            else cal(nowColor + 1, x1, y1, x2, y2);
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        color[c].push_back({ a,b });
    }
    if (K == 1) cout << "0";
    else {
        cal(1, 2e9, 2e9, -2e9, -2e9);
        cout << answer;
    }
    
}
