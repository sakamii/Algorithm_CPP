
#include <iostream>
using namespace std;
#define INF 2147483647

struct matrix {
    int row, col;
};
int n, dp[501][501];
matrix mat[501];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mat[i].row >> mat[i].col;

    for(int dist = 1; dist < n; dist++)
        for (int beg = 1; beg + dist <= n; beg++) {
            int end = beg + dist;
         
            dp[beg][end] = INF;
            for (int mid = beg; mid < end; mid++)
                dp[beg][end] = min(dp[beg][end], dp[beg][mid] + dp[mid + 1][end] + mat[beg].row * mat[mid].col * mat[end].col);
        }
    cout << dp[1][n];
}
