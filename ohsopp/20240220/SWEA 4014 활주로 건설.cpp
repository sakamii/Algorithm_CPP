
/*
  활주로의 행과 열을 각각 살펴보므로 입력 A의 전치행렬 B를 이용하여 같은 반복문 내에서 처리.
  calc 함수는 행렬 A를 매개변수로 줄 때는 garo, 행렬 B를 매개변수로 줄 때는 sero로 활주로가 가능한지 판단.
  (1) 현재가 이전 위치보다 1 높을 때
  (2) 현재가 이전 위치보다 1 낮을 때
  (3) 차이가 2 이상일 때(활주로 건설 불가)
  의 세 가지 경우로 나눈다.
*/

#include <iostream>
using namespace std;
 
int t, n, x, ans, garo, sero, A[22][22], B[22][22];
 
int calc(int i, int j, int arr[][22]) {
    int ret = 1;
 
    if (arr[i][j] == arr[i][j - 1] + 1) {   // (1)현재가 이전보다 1 높을 때
        int idx = j - 1;
        while (arr[i][j - 1] == arr[i][idx]) idx--;
        if (arr[i][idx] > arr[i][j - 1] && j - 1 - idx < 2 * x) ret = 0;
        else if (j - 1 - idx < x) ret = 0;
    }
    else if (arr[i][j] + 1 == arr[i][j - 1]) {  // (2)현재가 이전보다 1 낮을 때 (경사로 2개를 설치해야 하는 경우는 (1)의 22번 줄에서 처리할 수 있음)
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
                if (garo) garo = calc(i, j, A); // 가로(건설 가능 1, 건설 불가 0)
                if (sero) sero = calc(i, j, B); // 세로(건설 가능 1, 건설 불가 0)
            }
            ans += garo + sero;
        }
 
        cout << "#" << tc << " " << ans << endl;
        fill(A[0], A[22], 0);
        fill(B[0], B[22], 0);
        ans = 0;
    }
}
