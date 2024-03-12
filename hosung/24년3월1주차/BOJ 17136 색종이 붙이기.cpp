#include <iostream>

using namespace std;

/*
* 10X10맵이 고정이므로 완탐하여도 충분
* 크기를 5X5부터 1X1까지 하나씩 붙여가며 백트래킹을 진행하며
* 모두 붙여졌을 경우 붙인 개수를 정답과 비교해 작은 값을 저장한다
*/

int map[10][10];
int visited[10][10];
int papertype[6] = { 0,5,5,5,5,5 };
int ans = 21e8;

bool chk() { // 모두 종이가 덧붙여졌는 지 확인
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 1) { //아직 남아있다면 return
                return 0;
            }
        }
    }
    return 1;
}

bool patchpaper(int x, int y, int scale) {
    for (int i = x; i < x + scale; i++) {
        for (int j = y; j < y + scale; j++) {
            if (map[i][j] == 0) //덧붙이려는 데 종이가 아닌 부분이 있다면 쓸수없음
                return 0;
        }
    }
    return 1;
}

void recur(int level) {
    if (chk()) {
        ans = min(ans, level);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 1) { //덧붙일 수 있는 경우에만 종이를 덧붙임
                for (int s = 5; s >= 1; s--) { //종이의 크기를 모두 완탐
                    if (papertype[s] == 0) continue; //다 썼으면 넘김
                    if (i + s - 1 >= 10 || j + s - 1 >= 10) continue; //범위를 넘으면 넘김                    
                    if (patchpaper(i, j, s)) { //크기에 맞게 덧붙일 수 있는 지 확인
                        for (int k = i; k < i + s; k++) { //가능하면 한 만큼 지우기
                            for (int p = j; p < j + s; p++) {
                                map[k][p] = 0;
                            }
                        }
                        papertype[s]--; //사용한 색종이 줄이기
                        recur(level + 1);
                        papertype[s]++;
                        for (int k = i; k < i + s; k++) {
                            for (int p = j; p < j + s; p++) {
                                map[k][p] = 1;
                            }
                        }
                    }
                }
                return;
            }
        }
    }
    
}

int main() {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
        }
    }

    recur(0);
    
    if (ans == 21e8) cout << -1;
    else cout << ans;

    return 0;
}


