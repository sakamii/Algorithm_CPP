#include <iostream>
#include <algorithm>

using namespace std;
int play[10000];


int main() {
    //n : child m : play
    int n, m;
    long long int mmin = 1000000000;
    long long int mmax;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
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
    long long int mid = 0;
    while (mmin < mmax) {
        //속도 차이 나는 부분 (long long int) 8ms -> 4ms
        mid = (mmin + mmax) / (long long int)2;
        long long int nChild = 0;
        for (int i = 0; i < m; i++)
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

    int nChild = 0;
    mmax--;
    for (int i = 0; i < m; i++)
    {
        nChild += (mmax / play[i]);
    }
    mmax++;

    int k = 0;
    int c = n - nChild;
    for (k = 0; k < m; k++) {
        if (!(mmax % play[k])) {
            c--;
            if (!c) break;
        }
    }
    cout << k + 1;

}

