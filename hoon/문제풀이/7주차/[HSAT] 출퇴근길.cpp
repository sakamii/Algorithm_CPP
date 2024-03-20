#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

시작점과 탈출점이 방문할수 있는 노드를 구하는것이 먼저임.
그 공통된 지점이 정답의 후보군이 될수있음.
그러나 시작점에서부터 이동할떄 탈출점은 한번만 방문해야 하고
탈출점에서 이동할때 시작점은 한번만 방문해야하니
미리 방문처리를 해서, dfs에 들어가지 않도록 하자
또한, 방문했던곳을 재방문해서 cycle이 발생해도, 거기서 뻗어나가 탈출점으로 이동할수 있으면
OK이기때문에
visited를 dfs를 하는 동시에 하는것이 아닌
dfs의 시작점에서 현재 노드만 visited 해주는 것이 중요하다.

그리고, 각 공통된 지점에서 시작점 & 탈출점으로 다시 갈수있는 노드가 정답인 노드가 되게 되는데
이때, 공통된 지점 각각을 시작점으로 잡고 dfs를 돌리게 되면 당연히 시간초과가 난다.

그래서 역방향 그래프를 미리 저장해놓고
시작점 -> 시작점이 가능한 노드와
탈출점 -> 탈출점이 가능한 노드의 visted 배열을 각각 준비한다

총 4개 visited 배열이 활성화된 곳이 정답.

*/
int n, k;
// 정방향 간선
vector<int> v1[100001];
// 역방향 간선
vector<int> v2[100001];
int visited1[100001];
int visited2[100001];
int visited3[100001];
int visited4[100001];

void dfs(int idx, vector<int> v[], int visited[])
{
    if (visited[idx] == 1)
    {
        return;
    }
    visited[idx] = 1;
    for (int i = 0; i < v[idx].size(); i++)
    {
        dfs(v[idx][i], v, visited);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    int s, e;
    cin >> s >> e;
    visited1[e] = 1;
    visited2[s] = 1;
    dfs(s, v1, visited1);
    dfs(e, v1, visited2);
    dfs(s, v2, visited3);
    dfs(e, v2, visited4);

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == s || i == e)
            continue;
        if (visited1[i] && visited2[i] && visited3[i] && visited4[i])
        {
            count++;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << visited1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << visited2[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << visited3[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << visited4[i] << " ";
    // }
    // cout << endl;
    cout << count << endl;

    return 0;
}