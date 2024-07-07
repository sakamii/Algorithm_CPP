#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
dp[n][m] => 숫자 n을 1,2,3의 합으로 표현했을때 끝이 m인 것의 개수
m : 1 -> 무조건 하나
m : 2 -> 1,2로 이루어짐 ex) 1 1 1 2, 1 1 2, 1 2
m : 3 -> 1,2,3으로 이루어짐 ex) 1 2 3, 1 3 3, 1 2 2 3
1
1

2
1 1
2

3
1 1 1
1 2
3

4
1 1 1 1
1 1 2
2 2 
1 3

5
1 1 1 1 1
1 1 1 2
1 2 2 
1 1 3
2 3

2로 끝나는 경우 : 현재 숫자보다 2 작은 숫자의 1로 끝나는 수 + 2로 끝나는 수
3으로 끝나는 경우 : 현재 숫자보다 3 작은 숫자의 1로 끝나는 수 +
                    2로 끝나는 수 + 3으로 끝나는 수

dp[n][1] = dp[n-1][1]
dp[n][2] = dp[n-2][1] + dp[n-2][2]
dp[n][3] = dp[n-3][1] + dp[n-3][2] + dp[n-3][3]
*/

int dp[10001][4];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i=4; i<10001; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][2] + dp[i-2][1];
        dp[i][3] = dp[i-3][3] + dp[i-3][2] + dp[i-3][1];
    }
    for(int test_case = 1; test_case <= t; test_case++){
        int num;
        cin >> num;
        cout << dp[num][1] + dp[num][2] + dp[num][3] << endl;
    }
}