#include <iostream>
#include <algorithm>

using namespace std;
long long play[10000];


int main() {
    int n, m;
    long long mmin = 1000000000;
    long long mmax;
    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        cin >> play[i];
        if (mmin > play[i]) mmin = play[i];
    }

    if (n <= m) {
        cout << n;
        return 0;
    }
    n = n - m;
    mmax = mmin * n;
    long long mid = 0;
    while (mmin < mmax) {
        mid = (mmin + mmax) / (long long)2;
        long long nChild = 0;
        for (long long i = 0; i < m; i++)
        {
            nChild += mid / play[i];
        }

        if (nChild >= n) {
            mmax = mid;
        }
        else if (nChild < n) {
            mmin = mid + 1;
        }
    }


    long long nChild = 0;
    mmax--;
    for (long long i = 0; i < m; i++)
    {
        nChild += (mmax / play[i]);
    }
    mmax++;

    long long k = 0;
    long long c = n - nChild;
    for (k = 0; k < m; k++) {
        if (!(mmax % play[k])) {
            c--;
            if (!c) break;
        }
    }
    cout << k + 1;

}

