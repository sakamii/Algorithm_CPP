
/*
간단한 bs 문제
라고 생각했으나 오버플로우 이슈 때문에 소노 할 뻔.
end 값으로 가능한 최대를 10^18로 줘버리면 오버플로우 발생함.
따라서 end = 입력의 최댓값 + sqrt(b) 로 설정.
조금이라도 탐색하는 시간을 줄여보고자 정렬한 뒤 a[i] >= mid 이거나 예산이 b보다 커지면 break.
이때 두 조건의 flag값이 다르므로 조건문 따로 작성.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int n, maxn, a[100001];
ll b;

ll bs(ll s, ll e) {
    ll mid, ret = 0;

    while (s <= e) {
        mid = (s + e) / 2;

        ll sum = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= mid) break;
            if (sum + (mid - a[i]) * (mid - a[i]) > b) {
                flag = 1;
                break;
            }
            sum += (mid - a[i]) * (mid - a[i]);
        }

        if (!flag) {
            ret = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a+ n);
    
    cout << bs(0, a[n - 1] + sqrt(b));
}
