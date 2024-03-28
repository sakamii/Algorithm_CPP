#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

/*
    별다른 알고리즘이 보이지 않았고, 우선순위 큐? 정도 사용되나 생각함
    문제 조건이 번호가 낮은 혹은 창고 번호가 작은은 곳 부터라는 조건이 있었는데
    Index를 0부터 확인하면 우선순위 큐도 필요 없다고 생각함.
    단순 구현으로 문제를 접근해서 해결
*/

// num : 고객 번호, state : 창구에 들어가 있는 시간 체크, time : 해당 창구의 처리 시간
struct node {
    int num;
    int state;
    int time;
};

vector<node> n;
vector<node> m;
queue<int> k;
queue<int> wait;
queue<int> start;

int visited[1001];
int T, N, M, K, A, B;
int ans;

void solution() {

    // order : 고객 번호 카운팅
    // cnt : 접수/ 정비 창구에 존재하는 총 고객 숫자 의미
    // 창구에 모두 고객이 있는지 확인하는 용도
    int order = 1, flag = 1;
    int cnt_1 = 0, cnt_2 = 0;

    // flag : 모든 고객이 서비스 이용을 완료했다는 신호
    for (int t = 0; flag == 1; t++) {

        // 창구에 있는 시간 증가
        for (int j = 0; j < n.size(); j++) {
            if (n[j].state - 1 == 0) {
                // 다음 창구로 이동하는 경우
                n[j].state = 0;
                wait.push(n[j].num);
                cnt_1--;
            }
            else if (n[j].state > 0) n[j].state--;
        }

        for (int j = 0; j < m.size(); j++) {
            if (m[j].state - 1 == 0) {
                // 업무 완료 처리
                m[j].state = 0;
                cnt_2--;
            }
            else if (m[j].state > 0) m[j].state--;
        }

        // 손님이 t초에 도착하면 일단 start queue에 고객 번호와 함께 저장
        while (!k.empty()) {
            if (k.front() == t) {
                start.push(order);
                order++;
                k.pop();
            }
            else break;
        }

        while (1) {
            if (cnt_1 < n.size() && !start.empty()) {
                for (int i = 0; i < n.size(); i++) {
                    if (n[i].state == 0) {
                        // state = 0 --> 창구가 비어있다는 것을 의미
                        // i == A - 1은 A창구 이용한 고객 visited를 통해 기록
                        if (i == A - 1) visited[start.front()] = 1;
                        n[i].num = start.front();
                        n[i].state = n[i].time;
                        start.pop();
                        cnt_1++;
                        break;
                    }
                }
            }

            else break;
        }

        while (1) {
            if (!wait.empty() && cnt_2 < m.size()) {
                for (int i = 0; i < m.size(); i++) {
                    if (m[i].state == 0) {
                        // A창구를 이용하고 B창구도 이용한 고객 ans++
                        if (visited[wait.front()] == 1 && i == B - 1) ans += wait.front();
                        m[i].num = wait.front();
                        m[i].state = m[i].time;
                        wait.pop();
                        cnt_2++;
                        break;
                    }
                }
            }
            else break;
        }

        // 모든 고객이 이용을 마치면 flag = 0를 통해 루프문 해제
        if (k.empty() && start.empty() && wait.empty() && cnt_1 < 1) flag = 0;
    }


}

void input() {

    ans = 0;
    n.clear();
    m.clear();
    memset(visited, 0, sizeof(visited));

    cin >> N >> M >> K >> A >> B;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        n.push_back({ 0, 0, val });
    }

    for (int i = 0; i < M; i++) {
        int val;
        cin >> val;
        m.push_back({ 0, 0,val });
    }

    for (int i = 0; i < K; i++) {
        int val;
        cin >> val;
        k.push(val);
    }
}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input();

        solution();


        if (ans == 0) ans = -1;
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}
