//백준 2294 동전 2

/*
    pq로 모두 넣어서 구현
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int coin_sum[10000] = {-1};
int coins[100] = {0};
int n, k;

int find(int coin);

int main() {
    cin >> n >> k;
    fill(coin_sum, coin_sum + k + 1, k + 1);
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
        if(k >= coins[i]) {
            coin_sum[coins[i]] = 1;
            pq.push({-1, coins[i]});
        }
    }

    while(!pq.empty()) {
        int next_num = -pq.top().first + 1;
        int money = pq.top().second;
        pq.pop();

        for(int i = 0; i < n; i++) {
            int next_money = money + coins[i];
            if(next_money <= k) {
                if(coin_sum[next_money] > next_num)
                {
                    pq.push({-next_num, next_money});
                    coin_sum[next_money] = next_num;
                }
            }
        }
    
    }
    if(coin_sum[k] == (k + 1)) cout << -1;
    else cout << coin_sum[k];

    return 0;
}


//제귀 + 메모이즈 활용하기 위해 사용 
// 시간 초과
// 사용 방법 find(k)
int find(int f) {
    int min_sum = coin_sum[f];
    for(int i = 0; i < n; i ++) {
        if((f - coins[i]) <= 0) continue;
        else if(coin_sum[f - coins[i]] <= k) {
            min_sum = min(min_sum, coin_sum[f - coins[i]] + 1);
        }
        else {
            min_sum = min(min_sum, find(f - coins[i]) + 1);
        }

    }
    coin_sum[f] = min(min_sum, coin_sum[f]);

    return coin_sum[f];
}