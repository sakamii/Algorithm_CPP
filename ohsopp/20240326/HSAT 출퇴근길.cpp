
/*
양방향 간선과 사이클이 없는 그래프라면 (회사 -> 집), (집 -> 회사)로 두 번의 dfs로 탐색 가능하지만
양방향 간선과 사이클이 있으므로 여기에 추가로 (모든 노드 -> 집), (모든 노드 -> 회사)로의 두 번의 dfs를 추가 탐색해야함.

(모든 노드 -> 특정 노드)로 dfs를 탐색하기 위해서는 특정 노드로 들어오는 간선을 역으로 타고 들어가야 함.
네 번의 dfs에서 모두 방문되는 노드가 정답.
*/

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, m, s, t, a, b, ans;
vector<int> edge[100001];  // 순방향 간선
vector<int> reverse_edge[100001];  // 역방향 간선
bool vis[4][100001];

void dfs(int cur, vector<int> v[], bool* vis) {
    if (vis[cur])
        return;

    vis[cur] = 1;

    for (int i = 0; i < v[cur].size(); i++)
        dfs(v[cur][i], v, vis);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        reverse_edge[b].push_back(a);
    }

    cin >> s >> t;

    vis[0][t] = 1;
    vis[1][s] = 1;

    dfs(s, edge, vis[0]);  // 집 -> 회사
    dfs(t, edge, vis[1]);  // 회사 -> 집
    dfs(s, reverse_edge, vis[2]);  // 모든노드 -> 집
    dfs(t, reverse_edge, vis[3]);  // 모든노드 -> 회사

    for (int i = 1; i <= n; i++)
        if (i != s && i != t && vis[0][i] && vis[1][i] && vis[2][i] && vis[3][i])
            ans++;
    
    cout << ans;
}
