
#include <iostream>
#include <algorithm>
using namespace std;

int n, q, k, v[500003];

int bs(int tar) {
    int l = 1, r = n, mid;
  
    while (l <= r) {
        mid = (l + r) / 2;
        if (v[mid] < tar) l = mid + 1;
        else if (v[mid] > tar) r = mid - 1;
        else return mid;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    sort(v, v + n + 1);

    for (int i = 0; i < q; i++) {
        cin >> k;
        int idx = bs(k);
        cout << (idx - 1) * (n - idx) << '\n';
    }
}
