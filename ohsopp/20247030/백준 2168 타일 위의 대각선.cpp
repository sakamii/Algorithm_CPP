
#include <iostream>
using namespace std;

int x, y, ans;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> x >> y;
    
    if (gcd(x, y) == 1) ans = x + y - 1;
    else ans = x + y - gcd(x, y);

    cout << ans;
}
