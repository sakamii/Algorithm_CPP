#include <iostream>
#include <algorithm>
#include <queue>

/*
* 정직하게 구현하고 완탐 돌리는 게 핵심
*
* 최대 5번까지이므로 일단 5번하면 return한다.
* 이때 게임 맵을 이전 판 수를 통해 이번 판수를 옮겨야함으로
* 맵을 5번하는 관계로 3차원배열로 이전판수의 상황을 저장한다.
* 블록 처리 구현은
* 위로 올리는 것을 예를 들면
* 위로 블록을 올리게 되면 위쪽부터 같은 것은 합쳐지거나 남은 것을 고려해서
* 위에서 부터 아래로 블록들을 탐색하여 큐에 담는다.
* 이 때 0일 때는 담지 않는다 블록합성에 영향을 주지 않기 때문에
* 다 담고나면 다시 위에서부터 탐색하며 큐에 들어간 수를 확인한다
* 1.라인의 큐가 존재하는 지 확인한다.
* 1-1.큐가 비었다면 0으로 채운다,
* 1-2.비어있지 않다면, 앞에 있는 것을 now에 저장하고 pop을 한다.
* 2-1 이 상황에서 큐가 비어있지 않다면
* 큐에 머리와 now를 비교하여 같으면 둘은 합쳐지므로 현위치에 2배를 저장한 후 현재 큐머리를 pop한다
* 다르다면 그냥 now를 저장한다.
* 2-2 큐가 비어있다면 now를 저장한다
*
* 다른 것도 같은 방법으로 구현하였다.
*
* 기저조건에 도달하면 완탐으로 큰게 있으면 그것을 저장하면된다.
*/

using namespace std;

int map[6][20][20];
int mirr[4][20][20];
int N;
int maxblock;


void top(int lv) { //위로 올리거니까 합칠 때는 위에서 부터 합치는 거 확인
    queue<int>lnstk[20];
    //위에서부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[lv - 1][j][i] != 0) {
                lnstk[i].push(map[lv - 1][j][i]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[0][j][i] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[0][j][i] = now;
                }
                else mirr[0][j][i] = now;
            }
            else {
                mirr[0][j][i] = 0;
            }
        }
    }

}

void left(int lv) { //왼쪽으로 할거니까 합칠 때는 왼쪽부터 합치는 거 확인
    queue<int>lnstk[20];

    //왼쪽부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[lv - 1][i][j] != 0) {
                lnstk[i].push(map[lv - 1][i][j]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[1][i][j] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[1][i][j] = now;
                }
                else mirr[1][i][j] = now;
            }
            else {
                mirr[1][i][j] = 0;
            }
        }
    }
}

void bottom(int lv) { //아래로 내릴거니까 합칠 때는 아래에서 부터 합치는 거 확인
    queue<int>lnstk[20];
    int maxtmp = 0;
    //아래에서부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (map[lv - 1][j][i] != 0) {
                lnstk[i].push(map[lv - 1][j][i]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[2][j][i] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[2][j][i] = now;
                }
                else mirr[2][j][i] = now;
            }
            else {
                mirr[2][j][i] = 0;
            }
        }
    }


}

void right(int lv) { //오른쪽으로 할거니까 합칠 때는 오른쪽부터 합치는 거 확인
    queue<int>lnstk[20];
    int maxtmp = 0;
    //오른쪽부터 0이 아닌 것들을 큐에 담는다.
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (map[lv - 1][i][j] != 0) {
                lnstk[i].push(map[lv - 1][i][j]);
            }
        }
    }
    //임시 맵에다가 저장함
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {


            if (!lnstk[i].empty()) {
                int now = lnstk[i].front();
                lnstk[i].pop();
                if (!lnstk[i].empty()) {
                    if (now == lnstk[i].front()) {
                        mirr[3][i][j] = now * 2;
                        lnstk[i].pop();
                    }
                    else mirr[3][i][j] = now;
                }
                else mirr[3][i][j] = now;
            }
            else {
                mirr[3][i][j] = 0;
            }
        }
    }

}


void board(int lv) {
    if (lv == 6) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (maxblock < map[lv - 1][i][j]) {
                    maxblock = map[lv - 1][i][j];
                }
            }
        }
        return;
    }

    //위로 올리기
    top(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[0][i][j];
        }
    }
    board(lv + 1);




    //왼쪽으로 넣기
    left(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[1][i][j];
        }
    }
    board(lv + 1);



    //아래쪽으로 놓기
    bottom(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[2][i][j];
        }
    }
    board(lv + 1);

    //오른쪽으로 놓기
    right(lv);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[lv][i][j] = mirr[3][i][j];
        }
    }
    board(lv + 1);

}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[0][i][j];
        }
    }

    board(1);

    cout << maxblock;

    return 0;
}
