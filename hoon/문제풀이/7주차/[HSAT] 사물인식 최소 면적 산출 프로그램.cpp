#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define INF 200000001
using namespace std;

vector<pair<int, int>> v[21];
int n, k;
vector<pair<int, int>> temp;
int visited[21];
int answer = INF;

/*
가지치기를 안하면 무조건 틀리는 문제
문제 자체는 dfs를 통해
n개중 k개를 고르는 조합으로 문제를 풀고
k개중에서 min, max 범위를 찾아 면적을 구해주면 되는문제

그러나 가지치기를 안하면 시간초과가 난다.
그래서 k개를 구하는 과정에서
이미 앞에서 구한 answer가 더 작다면 더이상 탐색하는건 무의미
*/
void dfs(int idx, int min_x, int max_x, int min_y, int max_y)
{
    if (idx > k)
    {
        answer = min(answer, abs(min_x - max_x) * abs(min_y - max_y));
        return;
    }
    for (int i = 0; i < v[idx].size(); i++)
    {
        int temp_min_x = min(min_x, v[idx][i].first);
        int temp_max_x = max(max_x, v[idx][i].first);
        int temp_min_y = min(min_y, v[idx][i].second);
        int temp_max_y = max(max_y, v[idx][i].second);
        if (answer > abs(temp_min_x - temp_max_x) * abs(temp_min_y - temp_max_y))
            dfs(idx + 1, temp_min_x, temp_max_x, temp_min_y, temp_max_y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[c].push_back({a, b});
    }
    dfs(1, INF, -INF, INF, -INF);
    cout << answer << endl;
}