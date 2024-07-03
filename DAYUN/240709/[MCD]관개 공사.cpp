// 2024.07.04

// 알고리즘의 탑 - MST의 탑 4번 
// 최소 스패닝 트리 : 그래프의 최소 연결 부분 그래프
// MST알고리즘 새로 공부
/*
    그래프를 연결하는 최소 연결 부분 을 구하는 경우
    -> 특징 1 : 사이클이 만들어지지 않아야 한다.
    -> 특징 2 : 전체 노드(n) - 1개의 연결(간선)으로 구성된다.

    Kruskal Algorithm
        1. 사이클을 제거한다. : union find를 이용
        2. 가장 작은 거리를 모두 더한다. ( 연결 갯수 만큼 ) 

    Prim Algorithm

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1e9;

struct Node {
    int node1;
    int node2;
    int value;

    bool operator < (const Node &temp) const {
        return value > temp.value;
    };
};

int N;
int K;
int parent[2000];
priority_queue<Node> pq;
pair<int, int> field[2000];


void input();
void calDist();
int find(int num);

int main() {
    input();
    calDist();

    int result = 0; 
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        parent[i] = i;
    }
    
    int edgeNum = 0; 
    while((!pq.empty())) {
        int i = pq.top().node1;
        int j = pq.top().node2;
        int v = pq.top().value;
        pq.pop();

        if(find(i) != find(j)) {
            parent[parent[i]] = parent[parent[j]];
            edgeNum++;
            result += v;
        }
    }

    if(edgeNum != (N - 1)) {cout << -1;}
    else  {
        cout  << result;
    }
}

void input(){
    int y;
    int x;

    cin >> N;
    cin >> K;

    for(int i = 0; i < N; ++i) {
        cin >> y >> x;
        field[i] = {y, x};
    }
}

void calDist(){
    pair<int, int> ret;
    int minDist = MAX;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int dist = ((field[i].first - field[j].first) * (field[i].first - field[j].first)) + ((field[i].second - field[j].second) * (field[i].second - field[j].second));   
            if(dist >= K) {
                pq.push({i, j, dist});
            }
        }
    }
    return;
}

int find(int num) {
    if(parent[num] == num){
        return num;
    } 

    return parent[num] = find(parent[num]);
}