#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    냅색 문제를 푸는 방법은
    2차원 배열, 1차원 배열 2가지 방법 존재
    범위가 크기 때문에 1차원 배열로 해결ㄹ
*/

struct node {
    int w;
    int v;
};

vector<node> v;
vector<int> bag;
int N, K, M, ans;
int dp[1000001];

int main() {

    cin >> N >> M;

    v.push_back({ 0,0 });

    for (int i = 0; i < N; i++) {
        int weight, value;
        cin >> weight >> value;
        v.push_back({ weight, value });
    }

    for (int i = 0; i < M; i++) {
        int weight;
        cin >> weight;
        bag.push_back(weight);
        K = max(K, weight);
    }

    // 배낭의 최대 크기부터 시작해서 물건을 넣는다고 가정
    // 배낭 사이즈별로 첫번째 물건부터 넣어줌
    // 이후 물건별로 dp를 갱신하면서 넣어준다.

    // i는 물건 번호
    for (int i = 1; i <= N; i++) {
        // k는 배낭의 최대 크기부터 시작
        for (int j = K; j >= 0; j--) {
            // 배낭의 크기보다 물건이 크면 종료
            if (v[i].w > j) break;

            // dp[j - v[i].w]는 배낭 크기 j에서 현재 물건 v[i]을 넣고
            // 남은 크기의 들어갈 수 있는 최대 value 의미
            if (j - v[i].w >= 0) dp[j] = max(dp[j], dp[j - v[i].w] + v[i].v);
        }
    }


    //각 배낭 크기에 대한 효율 계산 파트
    ans = 1;
    float init = dp[bag[0]] / (float)bag[0];
    for (int i = 1; i < bag.size(); i++) {
        if (init < ((float)dp[bag[i]] / bag[i])) {
            ans = i + 1;
            init = ((float)dp[bag[i]] / bag[i]);
        }
    }

    cout << ans;

    return 0;
}
