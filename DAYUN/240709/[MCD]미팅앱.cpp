//24.07.05
// 최소신장 트리 Prim Algorithm으로 풀기 
/*
    Prim  Algorithm (Greedy) 
        1. 시작 위치 지정
        2. 가장 낮은 가중치를 고른다.
            인접한 노드가 가지고 있는 가장 낮은 가중치를 고르는 것
*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
char WorM[1001];
bool visited[1001];
vector<pair<int, int>> edges[1000];
priority_queue<pair<int, int>> pq;

void init();

int main() {
    int numLinkedNode = 0;
    int totalCost = 0;
    
    init();
    
    visited[1] = true;
    numLinkedNode++;
    for(int i = 0; i < edges[1].size(); i++) {
        pq.push(edges[1][i]);
    }
    
    while(!pq.empty()) {
        int nextNode = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(visited[nextNode]) continue;
        // cout << nextNode << " ";

        totalCost += cost;
        numLinkedNode++;
        visited[nextNode] = true;
        for(int i = 0; i < edges[nextNode].size(); i++) {
            if(visited[edges[nextNode][i].second]) continue;
            pq.push(edges[nextNode][i]);
        }
    
    }

    if(numLinkedNode == N) cout << totalCost;
    else cout << -1;
}

void init(){
    cin >> N;
    cin >> M;
    
    int node1;
    int node2;
    int cost;

    for(int i = 1; i <= N; i++) {
        cin >> WorM[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> node1 >> node2 >> cost;
        if(WorM[node1] == WorM[node2]) continue;
        edges[node1].push_back({-cost, node2});
        edges[node2].push_back({-cost, node1});
    }
}