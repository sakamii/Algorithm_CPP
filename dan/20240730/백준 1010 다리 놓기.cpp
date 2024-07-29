#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        int n, m, res = 1, tmp = 1;
        cin >> n >> m;

        for (int i = M; i > M - n; --i) {
            res = res * i;
            res = res / tmp++;
        }

        cout << res << "\n";
    }
    return 0;
}
