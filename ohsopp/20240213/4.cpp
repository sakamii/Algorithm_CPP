
// 풍선 사격 게임

#include <iostream>
using namespace std;

int t, n, ans, v[13] ={1};
bool vis[13];

void dfs(int d, int sum) {
  if (d == n) {
    ans = max(ans, sum);
    return;
  }
  
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      vis[i] = 1;
      int idx = i, tmp = 1;
      while (vis[idx]) idx--;
      tmp *= v[idx];
      idx = i;
      while (vis[idx]) idx++;
      tmp *= v[idx];
      if (d + 1 == n) dfs(d + 1, sum + v[i]);
      else dfs(d + 1, sum + tmp);
      vis[i] = 0;
    }
}

int main(){
  cin >> t;
  
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
      cin >> v[i];
    v[n + 1] = 1;
    
    ans = 0;
    dfs(0, 0);
    
    cout << "#" << tc << " " << ans << endl;
  }
}
