

#include <iostream>
#include <queue>
using namespace std;

int h, k, r, ans, total, w;
queue<int> v[2100];

void bi(int node, int day) {

    if (node * 2 > total) return;

    if (day % 2 && v[node * 2].size()) {
          v[node].push(v[node * 2].front());
          v[node * 2].pop();
    }
    else if (!(day % 2) && v[node * 2 + 1].size()) {
          v[node].push(v[node * 2 + 1].front());
          v[node * 2 + 1].pop();
    }

    bi(node * 2, day);
    bi(node * 2 + 1, day);
}

int main() {
    cin >> h >> k >> r;
    total = (1 << (h + 1)) - 1;

    for (int i = (1 << h); i <= total; i++)
        for (int j = 0; j < k; j++) {
            cin >> w;
            v[i].push(w);
        }

    for (int day = 0; day < r; day++) {
        if (v[1].size()) {
            ans += v[1].front();
            v[1].pop();
        }
        bi(1, day);
    }
    cout << ans;
}
