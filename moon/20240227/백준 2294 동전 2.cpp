#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    최소 동전 수를 구해야 하는 문제이기 때문에 
    bottom up 방식 사용을 사용하는 것이 편하다고 생각
    dp[i]는 i원을 처리할 수 있는 가장 작은 동전의 수를 의미
*/

vector<int> v;
int N, K, ans;
int dp[100001];

int main() {

    cin >> N >> K;

    fill(dp, dp + 100000, 10001);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        // 입력된 동전과 같은 값은 동전 하나로 처리 가능하기 때문에
        // 입력받는 과정에서 동전 개수 1로 저장
        // ex 50원 동전을 가지고 있는데 계산 값이 50원이라면 동전 1개만 필요
        dp[a] = 1;
    }

    for (int i = 1; i < 10001; i++) {
        // 동전 하나로 처리 가능한 경우 예외처리
        if (dp[i] == 1) continue;

        // 첫번째 동전부터 마지막 동전까지 전부 탐색하면서
        // 해당 동전을 사용 할 수 있는지 확인
        for (int k = 0; k < v.size(); k++) {
            // 현재 계산 값보다 동전의 값이 크면 계산이 필요없음.
            // ex) 계산값 100원, 동전 120원
            if (i - v[k] < 0) continue;

            // 해당 조건은 dp[i - v[k]] 값이 10001이 아닌 경우는
            // 이전 과정에서 동전을 사용해 계산을 진행한 경우
            // ex) 계산값 120원, 동전 20원, 60원인 경우
            //     dp에는 계산값 20, 60원에 대한 최소 동전 처리 횟수가 저장되어 있음.
            //     dp[120 - 20] = 5 로 갱신
            //     여기서 추가로 60원 동전이 존재하는 경우
            //     dp[120 - 60] = 1로 이전 값보다 개수가 작기 때문에 갱신
            if (dp[i - v[k]] != 10001) dp[i] = min(dp[i - v[k]] + 1, dp[i]);
        }

    }

    if (dp[K] == 10001) cout << -1;
    else cout << dp[K];


    return 0;
}
