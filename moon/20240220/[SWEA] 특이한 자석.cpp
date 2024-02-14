#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
    우선 자석의 개수가 4개 밖에 없기 때문에 복잡한 알고리즘이 필요 없다고 생각

    1. N번째 자석을 돌렸을 때 돌아가는 자석들 체크
    2. 체크된 자석을 방향에 맞게 회전
    3. K번 반복
*/

struct node {
    int num;
    int dir;
};

queue<node> q;
queue<node> check;

int visited[5];
int magnet[5][10];
int T, K, ans;

void rotation() {

    // check된 자석들 전부 pop 하면서 회전
    while (!check.empty()) {
        node change = check.front();
        check.pop();

        // 시계방향
        if (change.dir == -1) {
            int temp = magnet[change.num][1];
            for (int i = 2; i <= 8; i++) {
                magnet[change.num][i - 1] = magnet[change.num][i];
            }
            magnet[change.num][8] = temp;
        }
        // 반시계 방향
        else if (change.dir == 1) {
            int temp = magnet[change.num][8];
            for (int i = 7; i >= 1; i--) {
                magnet[change.num][i + 1] = magnet[change.num][i];
            }
            magnet[change.num][1] = temp;
        }

    }
   
}


void check_rotation(int n, int d) {
    
    // left : 왼쪽자석, right : 오른쪽 자석
    int left = n - 1;
    int right = n + 1;

    // 확인하는 조건
    // 1. index가 넘어가는지 확인
    // 2. 이미 회전시킨 자석인지 확인
    // 3. 인접하는 면이 서로 다른 극을 가르키는지 확인
    // 4. 조건이 모두 성립하면 방문처리 + check


    // 왼쪽 조건
    if (left > 0 && visited[left] == 0 && magnet[n][7] != magnet[left][3]) {

            
        visited[left] = 1;
        check.push({ left, d * -1 });

        // left 자석에 의해 이후 자석이 돌아가는지 확인하기 위해
        check_rotation(left, d * -1);
    }

    // 오른쪽 조건
    if (right < 5 && visited[right] == 0 && magnet[n][3] != magnet[right][7]) {
        visited[right] = 1;
        check.push({ right, d * -1 });

        // right 자석에 의해 이후 자석이 돌아가는지 확인하기 위해
        check_rotation(right, d * -1);
    }

    return;
}

void solution(int x) {
     
    // queue에 K번 돌리는 경우 모두 들어가 있음
    while (!q.empty()) {
        // now : 처음 돌아가는 자석의 번호와 방향 의미
        node now = q.front();

        // check : 돌아가야 하는 자석들의 번호와 방향이 들어가 있음.
        check.push({ now.num, now.dir });
        q.pop();

        // visited : 이미 회전하는 자석을 중복해서 돌리지 않기 위해 방문 체크
        visited[now.num] = 1;

        // now자석에 의해 회전을 하는지 체크하는 함수
        check_rotation(now.num, now.dir);

        // 체크된 자석들을 진짜 회전시키는 함수
        rotation();

        // 방문 초기화
        fill(visited, visited + 5, 0);
    }

    // 1 ~ 4 번째 각 자석의 첫번째 극을 확인하여 S극이면 ans++
    if (magnet[1][1] == 1) ans += 1;
    if (magnet[2][1] == 1) ans += 2;
    if (magnet[3][1] == 1) ans += 4;
    if (magnet[4][1] == 1) ans += 8;
    
}

void input(int x) {

    // K = 자석을 돌리는 횟수
    cin >> K;

    ans = 0;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> magnet[i][j];
       }
    }

    // 회전하는 자석과 방향을 queue에 삽입
    for (int i = 0; i < K; i++) {
        int n, d;
        cin >> n >> d;
        q.push({ n,d });
    }

}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input(0);

        solution(0);
        
        
        cout << "#" << t << " " << ans << endl;
        
        
    }


    return 0;
}
