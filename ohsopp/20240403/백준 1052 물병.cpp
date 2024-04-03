
#include <iostream>
using namespace std;

int n, k, cnt, tmp, ans;

int main() {
	cin >> n >> k;
  
    while (1) {
        cnt = 0, tmp = n + ans;
        while (tmp) {
            cnt += tmp % 2;
            tmp >>= 1;
        }
        if (k >= cnt) break;
        ans++;
    }
    cout << ans;
}
