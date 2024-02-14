#include <iostream>
#include <algorithm>

using namespace std;

int  m, n;
long long t[100000];

int main() {
    //3079 입국심사
    long long maxt = 0;
    long long mint = 0;
    long long result = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        maxt = max(maxt, t[i]);
    }

    maxt = maxt * m;
    while (mint <= maxt) {
        long double mt = 0;
        long long midt = (maxt + mint) / 2;
        for (int i = 0; i < n; i++) {
            mt += (midt / t[i]);
        }
        if (mt >= m) {
            maxt = midt - 1;
            result = midt;
        }
        else {
            mint = midt + 1;
        }
    }

    cout << result;
}
