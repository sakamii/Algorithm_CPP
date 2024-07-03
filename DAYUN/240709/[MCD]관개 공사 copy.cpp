// 2024.07.04

// 답지 보고 비교 및 공부


#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1e9;

struct Edge {
    int node1;
    int node2;
    int value;
};

bool cmp(Edge a, Edge b) {
    return a.value < b.value;
}

int N;
int K;
int parent[2000];
vector<Edge> pq;
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
    sort(pq.begin(), pq.end(), cmp);
    for(int k = 0; k < pq.size(); k++) {
        int i = pq[k].node1;
        int j = pq[k].node2;
        int v = pq[k].value;

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
                pq.push_back({i, j, dist});
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