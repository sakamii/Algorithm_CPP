/*
    K번 경기를 할 때, 나올 수 있는 경우

    영희가 이기는 경우 (k + 2) / 2 >= 차이
    동수가 이기는 경우 (k + 1) / 2 >= 차이
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, c, m, n;
    cin >> k >> c;

    for(int i = 0; i < c; i++) {
        cin >> m >> n;
        int ki = k - min(m, n);
        int dif = m - n;

        if(((ki + 2) / 2) >= dif && dif >= 0) cout << "1\n";
        else if(((ki + 1) / 2 >= -dif && dif < 0)) cout << "1\n";
        else cout << "0\n";
        
    }
}