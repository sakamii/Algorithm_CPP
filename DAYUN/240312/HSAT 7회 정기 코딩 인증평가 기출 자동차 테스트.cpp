/*
    1. 배열을 정렬한다.
    2. 배열에서 쿼리위치(m)을 찾는다.
    3. 정답 리턴 m * (n - m - 1)
*/

#include<iostream>
#include<algorithm>

int car[50000];

using namespace std;

int main(int argc, char** argv)
{
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> car[i];
    }
    sort(car, car + n);

    for(int i = 0; i < q; i++) {
        int k ;
        cin >> k;
        int l = 0;
        int h = n - 1;
        int m;
        while(l <= h) {
            m = (l + h) / 2;
            if(car[m] < k) {
                l = m + 1;
            }
            else if(car[m] > k){
                h = m - 1;
            }
            else {
                break;
            }
        }

        if(car[m] == k) {
            cout << m * (n - m - 1) << "\n";
        }
        else cout << 0 << "\n";
    }

   return 0;
}