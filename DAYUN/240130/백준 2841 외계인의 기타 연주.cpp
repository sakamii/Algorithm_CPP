#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

typedef struct melody {
    int n;
    int p;

    bool operator<(const melody& temp) const {
        if (n == temp.n) {
            return p > temp.p;
        }
        return n > temp.n;
    }
}melody;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, p;
    int ni, pi;
    int cnt = 0;
    vector<stack<int>> vs(6);
   
    cin >> n >> p;
    for (int i = 0; i < 6; i++)
    {
        vs[i].push(0);
    }

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;

        while (vs[x].top() > y)
        {
            vs[x].pop();
            cnt++;
        }
        if (vs[x].top() != y)
        {
            cnt++;
            vs[x].push(y);
        }
    }

    cout << cnt;
}