#include <iostream>

using namespace std;
int play[10000];


int main() {
    //n : child m : play
    long long n, m;
    long long mmin = 0;
    long long mmax = (long long)30 * (long long)2000000000;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> play[i];

    }

    // binary search
    if (n <= m) {
        cout << n;
        return 0;
    }
    n = n - m;

    long long mid = 0;
    long long t = 0;
    while (mmin <= mmax) {
        mid = (mmin + mmax) / (long long)2;
        long long nChild = 0;
        for (int i = 0; i < m; i++)
        {
            nChild += (long long)(mid / play[i]);
        }

        if (nChild >= n) {
            mmax = mid - 1;
            t = mid;
        }
        else if (nChild < n) {
            mmin = mid + 1;
        }
    }

    long long nChild = 0;
    t--;
    for (int i = 0; i < m; i++)
    {
        nChild += (t / play[i]);
    }
    t++;

    int k = 0;
    int c = 0;
    while (c < (n - nChild))
    {
        if ((t % play[k]) == 0) {
            c++;
        }
        k++;
    }
    cout << k;
}

