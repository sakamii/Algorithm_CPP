#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int arr1[100001];
int arr2[100001];
int n;
int t;
int dp[3][100001];
//각 위치의 값을 골랐을때의 최댓값
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n;
        for(int i=1; i<=n; i++) cin >> arr1[i];
        for(int i=1; i<=n; i++) cin >> arr2[i];
        dp[1][0] = 0;
        dp[2][0] = 0;
        dp[1][1] = arr1[1];
        dp[2][1] = arr2[1];
        for(int i=2; i<=n; i++){
            dp[1][i] = max(dp[2][i-1], dp[2][i-2]) + arr1[i];
            dp[2][i] = max(dp[1][i-1], dp[1][i-2]) + arr2[i];
        }
        cout << max(dp[1][n],dp[2][n]) << "\n";
    }
    return 0;
}