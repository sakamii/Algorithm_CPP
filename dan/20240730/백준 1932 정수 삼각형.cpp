#include <iostream>
using namespace std;
int t[504][504]; 
int dp[504][504]; 
int result = -1;
int mx(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int main(){
    int n;
    cin >> n;
    int idx = 1;
    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= i;j++){
            cin >> t[i][j];
        }
    }
    dp[1][1] = t[1][1];
    for (int i = 2; i <= n; i++){ 
        for (int j = 1; j <= i;j++){
            dp[i][j] = mx(dp[i - 1][j - 1], dp[i - 1][j]) + t[i][j];
        }
    }
    for (int i = 1; i <= n;i++){
        if(result < dp[n][i])
            result = dp[n][i];
    }
    cout << result; 
}
