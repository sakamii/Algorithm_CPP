// 백준 23061 백남이의 여행준비 

/*
    * 무게 별 최대 가치를 찾는다. * : result 배열에 저장(매번)
    1. 동전2와 동일 모든 물건을 더한다.
    2. 가치있는 value의 경우에만 벡터에 넣어 저장한다.
    2.1 가치있는 value란, result에 저장된는 경우
*/

#include <iostream>
#include <queue>

using namespace std;

//물건의 가치 V
int values[100];
//물건의 무게 W
int weights[100];
// 무게별 최대 가치
int result[1000001] = {0};
//가방이 견딜 수 있는 최대 무게 Ki
int bags[100];
//의미 있는 물건들의 조합
vector<pair<int, int>> v;

int main() {
    int n, m;
    cin >> n >> m;
    // 가방이 견딜 수 있는 최대 무게
    int maxBag = 0;
    for(int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> bags[i];
        maxBag = max(bags[i], maxBag);
    }
    //처음 무게를 넣기 위해 세팅
    v.push_back({0, 0});
    
    //i번째 물건을 넣는 경우
    for(int i = 0; i < n; i++) {
        int v_size = v.size();
        for(int j = 0; j < v_size; j++) {
            //i번째 물건 + 기존의 물건 조합
            int weight = v[j].first + weights[i];
            int value = v[j].second + values[i];
            //의미 있는 조합인지 판별 (result를 갱신하는 지)
            int flag = false;
            //weight가 크면 무조건 그 조합을 넣을 수 있으므로 모두 갱신
            for(int w = weight; w <= maxBag; w++){
                if(result[w] < value) {
                    result[w] = value;
                    flag = true;
                } 
                else {
                    //result는 무조건 오름차순으로 정렬되어 있다.
                    break;
                }
            } 
            if(flag) {
                v.push_back({weight, value});
            }
        }
    }

    int effective_bag_num = -1;
    double effectivity = -1;
    for(int i = 0; i < m; i++) {
        //double로 연산
        double now =  (double)result[bags[i]] / (double)bags[i];
        if(effectivity < now) {
            effective_bag_num = i;
            effectivity = now;
        }
    }
    cout << effective_bag_num + 1 << endl;
    
}