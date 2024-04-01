#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

/*
중요 : 트리에서의 dfs는 visited가 필요없다. prev 노드를 기억해 dfs 인자로 넣어주어, 반대로만 가지 않게 해주면 된다
트리 : cycle이 발생하지 않는 그래프
*/

int n, m;
vector<pair<int, int>> v[1001];
int s, e;
int answer = 0;
void dfs(int idx, int prev, int dist)
{
    if (idx == e)
    {
        // cout << dist << endl;
        answer = dist;
        return;
    }

    for (int i = 0; i < v[idx].size(); i++)
    {
        if (v[idx][i].first == prev)
            continue;
        dfs(v[idx][i].first, idx, dist + v[idx][i].second);
    }
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        dfs(s, -1, 0);
        cout << answer << endl;
    }
}