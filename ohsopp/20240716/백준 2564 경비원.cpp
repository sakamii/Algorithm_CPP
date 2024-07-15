#include <iostream>
using namespace std;

int w, h, n, p, x, sum, s[101];

int cal(int p, int x, int w, int h) {
    if (p == 1) return h + x;
    if (p == 2) return 2 * (w + h) - x;
    if (p == 3) return h - x;
    return w + h + x;
}

int main() {
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> x;
        s[i] = cal(p, x, w, h);
    }
    
    cin >> p >> x;
    x = cal(p, x, w, h);
    w = 2 * (w + h);
    
    for (int i = 0; i < n; i++) {
        p = (s[i] - x + w) % w;
        if (p * 2 > w) p = w - p;
        sum += p;
    }
    cout << sum;
}
