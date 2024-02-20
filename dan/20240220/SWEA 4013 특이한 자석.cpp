#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int magnet[5][9];
struct lr {
    int l, r;
};
vector<lr>mag_now(5);
int t, k;

int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int ans = 0;
        cin >> k;
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> magnet[i][j];
            }
            mag_now[i].l = 6;
            mag_now[i].r = 2;
        }
        int de = -1;
        for (int i = 0; i < k; i++) {
            int de2 = -1;
            int no, dir;
            cin >> no >> dir;
            int movement[5] = { 0 };
            movement[no] = dir;
            // 왼쪽 오른쪽 살펴야하는데 출발을 no 부터
            // 왼쪽 확인(최대 3회)
            int left = no - 1;
            for (int j = 0; j < 3; j++) {
                if (left < 1)continue;
                if (magnet[left][mag_now[left].r] == magnet[no - j][mag_now[no - j].l]) break;
                if (movement[no - j] == -1) { // <- 이거 잘못 짰다 no-j의 디렉션 알아야되니까 배열로 해야댓는데 ㅅㅂ
                    movement[left] = 1;
                }
                else {
                    movement[left] = -1;
                }
                left--;
            }
            // 오른쪽 확인
            int right = no + 1;
            for (int j = 0; j < 3; j++) {
                if (right > 4)continue;
                if (magnet[right][mag_now[right].l] == magnet[no + j][mag_now[no + j].r]) break;
                if (movement[no + j] == -1) {
                    movement[right] = 1;
                }
                else {
                    movement[right] = -1;
                }
                right++;
            }
            // 남은 자석들 돌리기
            for (int i = 1; i <= 4; i++) {
                int direction = movement[i];
                if (direction == -1) {
                    mag_now[i].l = (mag_now[i].l + 1) % 8;
                    mag_now[i].r = (mag_now[i].r + 1) % 8;
                }
                else if (direction == 1) {
                    mag_now[i].l = (mag_now[i].l + 7) % 8;
                    mag_now[i].r = (mag_now[i].r + 7) % 8;
                }
            }
        }
        for (int i = 1; i <= 4; i++) {
            int topn = (mag_now[i].l + 2) % 8;
            if (magnet[i][topn] == 1) ans += pow(2, (i - 1));
        }
        cout << "#" << tc << " " << ans << endl;
    }
}
