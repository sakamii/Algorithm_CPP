// 백준 23061 백남이의 여행준비 

/*
    백남이 여행
    필수품 N개 
    각 물건 w, v
    가방 m
    최대 ki 만큼 무게 
    가방에 최대로 
    각 무게 별 최대 효율 찾기
*/

#include <iostream>
#include <queue>

using namespace std;

//value 0 weight 1
int values[100];
int weights[100];
int weight[1000001] = {0};
int bags[100];
//-value, weight
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v;

int main() {
    int n, m;
    cin >> n >> m;
    fill(weight, weight + 1000001, 0);
    for(int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
        weight[weights[i]] = values[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> bags[i];
    }

    //무게 별 가장 효율적인 것 
    //0번 모두 사용 , 1번 모두 사용 
    for(int i = 0; i < n; i++ ){
        v.push_back({stocks[i][0], stocks[i][1]});
        for(int j = 0; j < v.size(); j++) {
            if(weight[stocks[i][1]])
        }
    }

    
}