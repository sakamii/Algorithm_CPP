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
    int time = 0;
    if (n <= m) {
        cout << n;
        return 0;
    }
    n = n - m;

    //mmax *= n;
    long long mid = 0;
    long long t = 0;
    while (mmin < mmax) {
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

    //find min n
    //cout << mid << " " << mmin << " " << mmax << endl;
    // t가 딱 n명째 태우는 정확한 시간
    // t-1일 때 몇명 태우는지? 그 뒤로 운행시간 mod 연산이 0이 될때마다 1씩추가

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

//딱 1초 전만 확인하면 된다.
//long long으로 변환


//최소공배수
