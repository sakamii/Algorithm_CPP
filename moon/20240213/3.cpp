#include<iostream>
#include<algorithm>
using namespace std;

int arr[30][30];
int visited[30][30];
int T, N, M;
int ans;
// int ans, sum, cnt;
int dir_even[6][2] = { {-1,0},{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1} };
int dir_old[6][2] = { {-1,0},{-1,1}, {0,1}, {1,0}, {0,-1}, {-1,-1} };

void dfs(int y, int x, int cnt, int sum) {
   if (cnt >= 3) {
      ans = max(ans, sum);
      return;
   }

   for (int i = 0; i < 6; i++) {
      int dy, dx;
      if (x % 2 == 0) {
         dy = y + dir_even[i][0];
         dx = x + dir_even[i][1];
      }
      else if (x % 2 == 1) {
         dy = y + dir_old[i][0];
         dx = x + dir_old[i][1];
      }
      if (dy > N || dx > M || dy < 1 || dx < 1 || visited[dy][dx]) continue;

      visited[dy][dx] = 1;
      dfs(dy, dx, cnt + 1, sum + arr[dy][dx]);
      visited[dy][dx] = 0;
   }
   
}

int main() {
   
   cin >> T;

   for (int t = 1; t <= T; t++) {
      cin >> N >> M;
      ans = 0;

      fill(arr[0], arr[20], 0);
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            visited[i][j] = 0;
         }
      }
      
      for (int i = 1; i <= N; i++) {
         for (int j = 1; j <= M; j++) {
             
             if (j % 2) {
                 ans = max(ans, arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j]);
                 ans = max(ans, arr[i][j] + arr[i - 1][j - 1] + arr[i - 1][j + 1] + arr[i + 1][j]);
             }
             else {
                 ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i + 1][j + 1] + arr[i + 1][j - 1]);
                 ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j - 1] + arr[i + 1][j]);
             }
           
           	 visited[i][j] = 1;
             // sum += arr[i][j];
             dfs(i, j, 0, arr[i][j]);
             visited[i][j] = 0;
     

//            if (j > 0 && j < M - 1 && j % 2 == 1 && i < N - 1) {
//               sum = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j];
//               ans = max(ans, sum);
//               if (i > 0) {
//                  sum = arr[i][j] + arr[i - 1][j] + arr[i + 1][j - 1] + arr[i + 1][j + 1];
//                  ans = max(ans, sum);
//               }
//            }
//            if (j > 0 && j < M - 1 && j % 2 == 0 && i > 0) {
//               sum = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j];
//               ans = max(ans, sum);
//               if (i > N - 1) {
//                  sum = arr[i][j] + arr[i - 1][j - 1] + arr[i - 1][j + 1] + arr[i + 1][j];
//                  ans = max(ans, sum);
//               }
//            }
//
            // sum = 0;
            
         }
      }

      cout << "#" << t << " " << ans << endl;

   }

}
