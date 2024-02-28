#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[102][102];
int N, answer;
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };
//하드코딩임. 어느 박스에 특정 방향으로 들어오면 특정 방향으로 재설정하는 것
int block[6][5] = { {0,0,0,0,0}, {0,0,0,2,1},{0,2,0,0,3},{0,4,3,0,0},{0,0,1,4,0},{0,0,0,0,0} };
struct loc {
    int x, y;
};
vector<loc> wormhole[11];

void cal(int x, int y, int dir) {
    int nx = x, ny = y, ndir = dir;
    int tempVal = 0;
    while (true) {
        nx += dx[ndir];
        ny += dy[ndir];
        
        //주변에 박스가 있을 때 시작함
				//가장 처음인 경우에 tempVal==0인데 arr[nx][ny]가 0이 아니라면 주변에 뭔가가 있음
        if (arr[nx][ny] == 0 && tempVal == 0) break;

        if (arr[nx][ny] == -1 || (nx == x && ny == y)) {
            answer = max(answer, tempVal);
            break;
        }

        //방향이 바뀌지 않고 그대로 돌아가면?
        //현재까지 점수 * 2와 방금 부딪힌 횟수 1을 더한다
        //다시 출발 위치로 돌아갈꺼니까

        //경기장 외벽과 부딪혔을 때
				//요거 넣었을 때 49개 맞음 왜 경기장 바깥부분을 5로 바꿨을 때 통과하는지는
				//모르겠음
        /*if (nx > N || ny > N || nx < 1 || ny < 1) {
            answer = max(answer, tempVal * 2 + 1);
            break;
        }*/

        //블록 만났을 때
        if (0 < arr[nx][ny] && arr[nx][ny] <= 5) {
            ndir = block[arr[nx][ny]][ndir];
            if (ndir == 0) { //0이 현재 방향 정확히 180도 반대로 되돌아가는 경우
                answer = max(answer, tempVal * 2 + 1);
                break;
            }
            else tempVal++;
        }
        else if (arr[nx][ny] > 5) {//웜홀 만나면 그냥 반대편 웜홀로 보내준다.
            int tempnx = nx;
            int tempny = ny;
            if (nx == wormhole[arr[nx][ny]][0].x && ny == wormhole[arr[nx][ny]][0].y) {
                tempnx = wormhole[arr[nx][ny]][1].x;
                tempny = wormhole[arr[nx][ny]][1].y;
            }
            else {
                tempnx = wormhole[arr[nx][ny]][0].x;
                tempny = wormhole[arr[nx][ny]][0].y;
            }
            nx = tempnx;
            ny = tempny;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int x = 1; x <= tc; x++) {
        cin >> N;
        //경기장 바깥쪽을 5로 만들기 요게 키포인트인듯
        for (int i = 0; i < N + 2; i++) {
            arr[0][i] = 5;
            arr[i][0] = 5;
            arr[N + 1][i] = 5;
            arr[i][N + 1] = 5;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> arr[i][j];
                if (arr[i][j] > 5) {
										//6 이상일 때 wormhole이니까 위치를 넣어준다.
                    loc temp;
                    temp.x = i;
                    temp.y = j;
                    wormhole[arr[i][j]].push_back(temp);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] == 0) { //비어있는 경우가 시작될 수 있는 경우
                    for (int k = 1; k <= 4; k++) {
                        cal(i, j, k);
                    }
                }
            }
        }
        cout << '#' << x << ' ' << answer << '\n';
        for (int i = 6; i < 11; i++) {
            wormhole[i].clear();
        }
        answer = 0;
    }
}