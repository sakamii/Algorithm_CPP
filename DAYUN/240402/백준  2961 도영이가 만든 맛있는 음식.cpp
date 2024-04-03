#include<iostream>
#include <algorithm>

using namespace std;
int food[10][2];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> food[i][0] >> food[i][1];
    }

    long long mmin = 1e18;
    for(int i = 1; i <(1 << n); i++) {
        long long b = 0;
        long long s = 1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                s *= food[j][0];
                b += food[j][1];
            }
        }
        mmin = min(mmin, abs(s - b));
    }

    cout << mmin;
}