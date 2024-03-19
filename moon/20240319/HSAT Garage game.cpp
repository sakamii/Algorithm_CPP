#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

/*
    보자마자 일단 완전탐색(DFS)을 해봐야 겠다고 생각
    1. N이 크지않음
    2. 사각형 map 안에서 연산이 이루어짐
    3. 최대 3번의 계산값만 구하면 됨

    사각형 안에서 탐색을 시작하는 곳 선택 --> DFS
    사각형의 면적 구하기 --> BFS
    사라진 칸 채우기 --> 중력
    
    위 세가지 연산이 이루어 져야 하기 때문에
    사각형 안에 들어있는 값이 모두 다른 경우 --> worst case
    탐색하는 과정에서 시간이 많이 소모됨

    구현 후 시간초과가 계속 일어나서 여러가지 방법으로 시간 줄일려고 노력
    1. vector --> 배열로 교체
    2. 함수 호출 횟수 최대한 줄임
    3. 중력 작용 필요한 곳만 시킴
    4. BFS, DFS 과정에서 최대한 가지치기

    visited 배열을 포인터로만 넘겨주어야 한다는 
    생각 때문에 쉽게 해결 못함 --> DFS와 BFS visited 배열 공유 시킴

    2번의 연산이 진행된 후에는 최고 면적값만 구하고
    중력이나 기타 작업이 필요 없다.
*/

// y = 탐색한 노드의 수
// x = 면적
struct node {
    int y;
    int x;
};

// node v는 bfs로 지나간 좌표값을 저장
node v[225];
int col[50];
int N, ans, vsize;
int car_map[50][20];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };


// 면적 구하기 bfs
node bfs(int y, int x, int visited[][20]) {

    queue<node> q;
    q.push({ y,x });

    // vise = 방문한 노드 수
    vsize = 0;
    v[0] = { y,x };

    visited[y][x] = 1;

    // count = 방문한 노드수
    int count = 1;

    // 면적을 구하기 위해
    // max는 탐색된 노드의 최고 y,x 좌표를 저장
    // min은 탐색된 노드의 최저 y,x 좌표를 저장
    node max = { y,x };
    node min = { y,x };

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        //좌표값 갱신
        if (now.y > max.y) max.y = now.y;
        if (now.x > max.x) max.x = now.x;
        if (now.y < min.y) min.y = now.y;
        if (now.x < min.x) min.x = now.x;

        for (int i = 0; i < 4; i++) {
            int dy = now.y + dir[i][0];
            int dx = now.x + dir[i][1];

            if (dy >= 3 * N || dx >= N || dy < 2 * N || dx < 0) continue;
            if (visited[dy][dx]) continue;
            if (car_map[y][x] != car_map[dy][dx]) continue;

            visited[dy][dx] = 1;
            count++;
            q.push({ dy,dx });

            //방문한 노드 좌표를 v에 저장
            v[++vsize] = { dy,dx };
        }
    }

    // count = 방문한 노드 수
    // 오른쪽은 score = 방문한 노드 수 + 최대 면적 값
    return { count, count + ((max.y - min.y + 1) * (max.x - min.x + 1)) };
}

// 탐색을 시작할 곳을 선택하는 DFS
// 모든 노드가 탐색 대상
// level = 연산 진행 횟수, score = 현재 점수 총합
void dfs(int level, int score) {

    // 방문처리 위해
    // level이 바뀔때마다 초기화 해주어야 함
    // --> level이 바뀌면 처음부터 다시 탐색해야 됨
    int visited[50][20] = { 0, };
    
    // return후 map 복구를 위해 원본값 저장
    int cp_car_map[50][20] = { 0, };

    // 중력을 작용할 col 저장
    int check[50] = { 0, };

    // 3번째 연산에서는 map이 손상되지 않고, 결과값만 구함
    if (level < 2) memcpy(cp_car_map, car_map, sizeof(car_map));

    for (int i = 2 * N; i < 3 * N; i++) {
        for (int j = 0; j < N; j++) {
            // 방문한 node인 경우
            if (visited[i][j]) continue;

            // 면적 구하기
            node sum_arr = bfs(i, j, visited);

            // 중력이 작용하는 col의 갯수
            int colsize = 0;

            // sum_arr.y = 방문한 노드의 수
            // 방문한 곳만 중력이 작용함
            for (int k = 0; k < sum_arr.y; k++) {
                // 방문처리
                visited[v[k].y][v[k].x] = 1;
                // 원본 map 값 삭제
                car_map[v[k].y][v[k].x] = 0;

                // 중력 작용 체크를 안한 경우
                if (!check[v[k].x]) {
                    // 
                    col[colsize++] = v[k].x;
                    check[v[k].x] = 1;
                }
                // 중력 체크 했으니깐 값 초기화
                v[k] = { 0,0 };
            }

            // 중력 작용 코드
            if (level < 2) {
                queue<int> q;

                //중력이 작용하는 곳이 있는 경우
                while (colsize > 0) {

                    // j = 중력 작용하는 col
                    int j = col[--colsize];

                    // 중력 체크했으니깐 초기화
                    col[colsize] = 0;

                    // 중력 실행
                    // map 값이 0인 경우는 continue하고
                    // 값이 있는 경우에만 queue 삽입
                    // ex) map = 1110110 --> queue = 11111
                    for (int i = 3 * N - 1; i > -1; i--) {
                        if (!car_map[i][j]) continue;
                        q.push(car_map[i][j]);
                        car_map[i][j] = 0;
                    }

                    // queue를 pop 하면서 map의 아래부터 값을 채움
                    // idx는 맨아래부터 채우기 위해
                    int idx = 3 * N - 1;
                    while (!q.empty()) {
                        car_map[idx][j] = q.front();
                        q.pop();
                        idx--;
                    }
                }
                
                // 연산 1번 진행했으니까 level 늘려주고
                // sum_arr.x 는 현재 level의 score 값
                // score = 이전연산에서 넘어온 점수
                dfs(level + 1, score + sum_arr.x);

                // return 후 값 복구
                memcpy(car_map, cp_car_map, sizeof(cp_car_map));
                for (int k = 0; k < N; k++) {
                    check[k] = 0;
                }   
            }

            // 3번째 연산의 경우 bfs 탐색으로 score만 더해줌
            // 중력 x 
            else ans = max(ans, score + sum_arr.x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < 3 * N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> car_map[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << "\n";

    return 0;
}
