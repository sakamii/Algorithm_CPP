#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int s;
    int dist;
    int last_node;
};

vector<pair<int, int>> tree[1000];
queue<node> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int s, e, dist;
        cin >> s >> e >> dist;
        tree[s].push_back({e, dist});
        tree[e].push_back({s, dist});
    }

    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        q.push({s, 0, -1});
        bool flag = true;
        while(!q.empty()){
            node n = q.front();
            q.pop();
            for(int j = 0; j < tree[n.s].size(); j++) {
                if(tree[n.s][j].first == e) {
                    cout << n.dist + tree[n.s][j].second << "\n";
                    flag = false;
                    while(!q.empty()) {q.pop();}
                    break;
                }
                else if(tree[n.s][j].first != n.last_node){
                    q.push({tree[n.s][j].first, n.dist + tree[n.s][j].second, n.s});
                }
            }
        }
    }
}