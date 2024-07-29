
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, u, v, cnt = 1;
int visited[20001];
vector<vector<int> > adj(20001);
vector<int> ans;

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto& next : adj[cur]) {
            if (visited[next]) continue;
            if (visited[cur] + 1 == cnt) {
                visited[next] = visited[cur] + 1;
                q.push(next);
                ans.push_back(next);
            }
            else if (visited[cur] + 1 > cnt) {
                ans.clear();
                visited[next] = visited[cur] + 1;
                q.push(next);
                cnt = visited[next];
                ans.push_back(next);

            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << visited[ans[0]] - 1 << " " << ans.size();
}
