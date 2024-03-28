
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, c, v[11][14];
vector<int> res;

void dfs(int s, int e, int sum, int total, int r) {
    if (sum > c) return;
    
    v[r][11] = max(v[r][11], total);
    
    for (int i = s; i <= e; i++)
        dfs(i + 1, e, sum + v[r][i], total + v[r][i] * v[r][i], r);
}

int main() {
    cin >> t;
    
    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> m >> c;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cin >> v[i][j];
            v[i][11] = 0;
        }
        
        for (int i = 1; i <= n; i++)
            for (int k = 0; k < m; k++)
                for (int j = 1; j + k <= n; j++)
                    dfs(j, j + k, 0, 0, i);
        
        res.clear();
        for (int i = 1; i <= n; i++)
            res.push_back(v[i][11]);
        
        sort(res.begin(), res.end(), greater<>());
        
        cout << "#" << tc << " " << res[0] + res[1] << endl;
    }
}
