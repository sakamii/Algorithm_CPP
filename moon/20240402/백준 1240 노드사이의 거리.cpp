#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    문제에서 말하는 트리구조라는 말을 이해를 못해서
    다익스트라를 이용해서 품 --> 그냥 bfs 돌려서 만나면 최소값인데..
    트리구조는 노드에서 노드로 가는 경우의 수가 1개 밖에 없음!!!
*/

struct node {
    int node;
    int dis;
};

bool operator<(node a, node b) {
    if (a.dis > b.dis) return true;
    else if (a.dis < b.dis) return false;
    else {
        if (a.node > b.node) return false;
        else return true;
    }
}

vector<node> v[1001];
int dest[1001];
int N, M, ans;

// 단순 다익스트라
int bfs(int start, int end) {
    priority_queue<node> pq;
    pq.push({ start,0 });
    fill(dest, dest + 1001, 21e8);
    dest[start] = 0;

    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        if (now.node == end) return dest[now.node];

        for (int i = 0; i < v[now.node].size(); i++) {
            node next = v[now.node][i];
            int next_cost = next.dis + dest[now.node];
            if (next_cost >= dest[next.node]) continue;
            dest[next.node] = next_cost;
            pq.push({ next.node, next_cost });
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }

    for (int i = 0; i < M; i++) {
        ans = 21e8;
        int s, e;
        cin >> s >> e;
        cout << bfs(s, e) << "\n";
    }

    return 0;
}
