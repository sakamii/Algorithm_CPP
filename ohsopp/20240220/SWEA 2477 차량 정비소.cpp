
/*
  고객이 들어오고 나가는 시간을 기준으로 실행 속도 높일 있을 것 같은데 나한텐 너무 복잡해서
  매초마다 고객 도착, 빈 창고 고객 할당, 창고 대기열 관리 등을 완탐하여 모두 살펴보는 식으로 해결.
*/

#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

struct Info {
    int rec;
    int rep;
    int at; // 도착 시간
};
Info customer[1002];

int n, m, a, b, k, t, ans;

// 창고, 창고 이용 고객, 창고 별 걸리는 시간(n:접수, m:정비)
int n1[11], nc[11], nt[11];
int m1[11], mc[11], mt[11];

// 창고 대기큐
queue <int> nq;
queue <int> mq;

void solve() {
    memset(n1, -1, sizeof(n1));
    memset(m1, -1, sizeof(m1));
    int T = 0, out = 0;

    while (out < k) {
        // 1. 도착한 사람 큐에 넣기
        for (int i = 1; i <= k; i++)
            if (customer[i].at == T)
                nq.push(i);

        // 2. 접수 창고 끝난 사람 처리
        for (int i = 1; i <= n; i++)
            if (n1[i] == T) {
                n1[i] = -1;
                mq.push(nc[i]);
            }

        // 3. 접수 창고 비었으면 접수 대기큐에서 사람 빼서 넣기
        for (int i = 1; i <= n; i++)
            if (!nq.empty() && n1[i] == -1) {
                n1[i] = nt[i] + T;
                nc[i] = nq.front();
                customer[nq.front()].rec = i;
                nq.pop();
            }

        // 4. 정비 창고 끝난 사람 처리
        for (int i = 1; i <= m; i++)
            if (m1[i] == T) {
                m1[i] = -1;
                out++;
            }

        // 5. 정비 창고 비었으면 정비 대기큐에서 사람 빼서 넣기
        for (int i = 1; i <= m; i++)
            if (!mq.empty() && m1[i] == -1) {
                m1[i] = mt[i] + T;
                mc[i] = mq.front();
                customer[mq.front()].rep = i;
                mq.pop();
            }
        T++;
    }
}

int main() {
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cin >> n >> m >> k >> a >> b;
        for (int i = 1; i <= n; i++) cin >> nt[i];
        for (int i = 1; i <= m; i++) cin >> mt[i];
        for (int i = 1; i <= k; i++) cin >> customer[i].at;

        solve();

        ans = 0;
        for (int i = 1; i <= k; i++)
            if (customer[i].rec == a && customer[i].rep == b)
                ans += i;
        if (!ans) ans--;
        cout << "#" << tc << " " << ans << "\n";
    }
}
