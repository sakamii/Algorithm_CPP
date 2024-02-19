
#include <iostream>
using namespace std;
 
int t, n, x, ans, garo, sero, A[22][22], B[22][22];
 
int calc(int i, int j, int arr[][22]) {
    int ret = 1;
 
    if (arr[i][j] == arr[i][j - 1] + 1) {   // 현재가 이전보다 1 클 때
        int idx = j - 1;
        while (arr[i][j - 1] == arr[i][idx]) idx--;
        if (arr[i][idx] > arr[i][j - 1] && j - 1 - idx < 2 * x) ret = 0;
        else if (j - 1 - idx < x) ret = 0;
    }
    else if (arr[i][j] + 1 == arr[i][j - 1]) {  // 현재가 이전보다 1 작을 때
        int idx = j;
        while (arr[i][j] == arr[i][idx]) idx++;
        if (idx - j < x) ret = 0;
    }
    else if (arr[i][j] != arr[i][j - 1]) ret = 0;   // 차이가 2 이상 일 때
 
    return ret;
}
 
int main() {
    cin >> t;
 
    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> x;
 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> A[i][j];
                B[j][i] = A[i][j];
            }
 
        for (int i = 1; i <= n; i++) {
            garo = sero = 1;
            for (int j = 2; j <= n; j++) {
                if (!garo && !sero) break;
                if (garo) garo = calc(i, j, A); // 가로
                if (sero) sero = calc(i, j, B); // 세로
            }
            ans += garo + sero;
        }
 
        cout << "#" << tc << " " << ans << endl;
        fill(A[0], A[22], 0);
        fill(B[0], B[22], 0);
        ans = 0;
    }
}
