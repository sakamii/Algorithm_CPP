#include <iostream>

using namespace std;
int play[10000];


int main() {
    //n : child m : play
    int n, m;
    int mmin = 30, mmax = 0;
    //cin >> n >> m;
    n = 2000000000;
    m = 1;
    for (int i = 0; i < m; i++)
    {
        //cin >> play[i];
        play[i] = 1;
        if (mmin > play[i]) mmin = play[i];
        if (mmax < play[i]) mmax = play[i];
    }

    // binary search
    int time = 0;
    if (n <= m) {
        cout << n;
        return 0;
    }
    n = n - m;

    mmax *= n;
    int mid = 0;
    while (mmin < mmax) {
        //cout << mmin <<" " << mmax << endl;
        //mid = (mmin + mmax) / 2;
        mid = mmin / 2 + mmax / 2;
        int nChild = 0;
        for (int i = 0; i < m; i++)
        {
            nChild += (mid / play[i]);
        }

        if (nChild > n) mmax = mid - 1;
        else if (nChild < n) {
            mmin = mid + 1;
        }
        if(nChild == n) {
            break;
        }
    }

    //find min n
    //cout << mid << " " << mmin << " " << mmax << endl;


    int nChild = n;
    while (nChild == n) {
        nChild = 0;
        mid--;
        for (int i = 0; i < m; i++)
        {
            nChild += (mid / play[i]);
        }
    }
    mid++;

    int k = -1;
    int c = 0;
    //cout << n - nChild << endl;
    while (c < (n - nChild))
    {
        k++;
        if ((mid % play[k]) == 0) {
            c++;
            //cout << c << k << " ";
        }
    }
    cout << k + 1;



}




//최소공배수
