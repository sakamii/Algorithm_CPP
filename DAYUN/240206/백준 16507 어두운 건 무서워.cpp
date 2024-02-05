// 16507 어두운 건 무서워

#include<iostream>

using namespace std;

int arr[1001][1001] = {0};
int prefix_sum[1001][1001] = {0};

int main() {
    int R, C, q;
    cin >> R >> C >> q;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> arr[i][j];
        }
    }

    //prefix-sum
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + arr[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int sum = prefix_sum[r2][c2] - prefix_sum[r1 - 1][c2] - prefix_sum[r2][c1 - 1] + prefix_sum[r1 - 1][c1 - 1];
        cout << sum / ((r2 - r1 + 1) * (c2 - c1 + 1)) << endl;
    }
}