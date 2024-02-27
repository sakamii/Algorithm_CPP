#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
   dp의 i번째 값은 수열 i번째를 넣을 수 있는 
   경우중에서 가장 큰 경우를 의미
*/

vector<int> v;
int N, ans;
int dp[1001];

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    dp[0] = v[0];
    ans = dp[0];

    for (int i = 1; i < N; i++) {
        dp[i] = v[i];
        for (int j = 1; j <= i; j++) {
            if (v[i] > v[i - j] && dp[i] < dp[i - j] + v[i]) {
                dp[i] = dp[i - j] + v[i];
                ans = max(dp[i], ans);
            }
        }
    }


    cout << ans;

    return 0;
}
