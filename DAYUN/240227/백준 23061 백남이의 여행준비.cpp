// 백준 23061 백남이의 여행준비 

/*
    백남이 여행
    필수품 N개 
    각 물건 w, v
    가방 m
    최대 ki 만큼 무게 
    가방에 최대로 
    각 무게 별 최대 효율 찾기


    * 무게 별 최대 가치를 찾는다. * : result 배열에 저장
    1. 동전2와 동일 모든 물건을 더한다.
    2. 단, weight보다 작은 수 중에서 value가 큰 값이 있다면 value를 넣고 queue에 넣지는 않는다. 
    2. 최대 value찾기

    
*/

#include <iostream>
#include <queue>

using namespace std;

//value 0 weight 1
int values[100];
int weights[100];
int result[1000001] = {0};
int bags[100];
//-value, weight
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v;

int main() {
    int n, m;
    cin >> n >> m;
    int maxBag = 0;
    for(int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> bags[i];
        maxBag = max(bags[i], maxBag);
    }
    v.push_back({0, 0});
    
    for(int i = 0; i < n; i++) {
        int v_size = v.size();
        for(int j = 0; j < v_size; j++) {
            int weight = v[j].first + weights[i];
            int value = v[j].second + values[i];
            int flag = false;
            for(int w = weight; w <= maxBag; w++){
                if(result[w] < value) {
                    result[w] = value;
                    flag = true;
                } 
                else {
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
        double now =  (double)result[bags[i]] / (double)bags[i];
        // cout << now << " ";
        if(effectivity < now) {
            effective_bag_num = i;
            effectivity = now;
        }
    }
    // cout << endl;
    cout << effective_bag_num + 1 << endl;
    
}