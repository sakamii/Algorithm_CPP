// 백준 23061 백남이의 여행준비 

/*
    * 무게 별 최대 가치를 찾는다. * : result 배열에 저장(매번)
    1. 동전2와 동일 모든 물건을 더한다.
    2. 가치있는 value의 경우에만 벡터에 넣어 저장한다.
    2.1 가치있는 value란, result에 저장된는 경우
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//물건의 가치 V
int values[101];
//물건의 무게 W
int weights[101];
// 1번 ~i 번 까지 고려할 때 부피 j인 가치의 최대
int result[101][1000001];
//가방이 견딜 수 있는 최대 무게 Ki
int bags[100];
//의미 있는 물건들의 조합
vector<pair<int, int>> v;

int main() {
    int n, m;
    cin >> n >> m;
    // 가방이 견딜 수 있는 최대 무게
    int maxBag = 0;
    for(int i = 1; i <= n; i++) {
        cin >> weights[i] >> values[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> bags[i];
        maxBag = max(bags[i], maxBag);
    }
    
    //i번째 물건을 넣는 경우
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= maxBag; j++) {
            result[i][j] = result[i - 1][j];

            if(weights[i] <= j && result[i][j] < result[i - 1][j - weights[i]] + values[i] ) {
                result[i][j] = result[i - 1][j - weights[i]] + values[i];
            }
        }
    }

    int effective_bag_num = -1;
    double effectivity = -1;
    for(int i = 0; i < m; i++) {
        //double로 연산
        double now =  (double)result[n][bags[i]] / (double)bags[i];
        if(effectivity < now) {
            effective_bag_num = i;
            effectivity = now;
        }
    }
    cout << effective_bag_num + 1 << endl;
    
}