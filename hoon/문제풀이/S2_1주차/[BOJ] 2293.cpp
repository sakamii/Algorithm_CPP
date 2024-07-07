#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n,k;
int arr[101];
int dp[10001];
/*
첫번째풀이 dp2차원 -> 메모리초과

두번째풀이 dp 1차원으로 풀어보자
일반적으로 동전의 가격이 정해진 경우 동전의 갯수 -> 높은(or낮은) 동전부터 그리디하게

동전의 가격이 정해지지 않은 경우 -> 동적계획법 필요
ex) k = 10, 동전 1,2,5

1
1

2
1 1
2

3
1 1 1
1 2

4
1 1 1 1
1 1 2
2 2

5
1 1 1 1 1
1 1 1 2
1 2 2
5

규칙을 잘 살펴보면 다음과 같다
먼저 작은 동전부터 k 금액까지 만드는 횟수를 채움
그 다음 금액의 동전으로 만들수 있으면, 그 횟수만큼을 더해줌

점화식
dp[i] = dp[i] + dp[i- 현재동전]
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin  >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(j < arr[i]) continue;
            dp[j] = dp[j] + dp[j-arr[i]];
        }
    }
    cout << dp[k] << endl; 
    return 0;
}