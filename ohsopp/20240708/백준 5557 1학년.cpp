
#include <iostream>
using namespace std;

int i = 1, j, n, a[101];
long long dp[101][21];

main(){
    cin >> n;
    
    for(; i <= n; i++)
        cin>>a[i];
    
    dp[1][a[1]] = 1;
    
    for(i = 2; i < n; i++)
        for(j = 0; j <= 20; j++)
            if (dp[i - 1][j]) {
                if (j + a[i] <= 20)
                    dp[i][j + a[i]] += dp[i - 1][j];
                if (j - a[i] >= 0)
                    dp[i][j - a[i]] += dp[i - 1][j];
            }

    cout << dp[n - 1][a[n]];
}
