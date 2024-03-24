
/*
전체 로직 과정
1. 기본적으로 모든 도로가 비어있을 때까지 반복
2. 도로의 front가 모두 cur 보다 시간이 크다면 cur를 그중 가장 작은 값으로 갱신
3. (오른쪽 도로에 더이상 차가 없거나 || 있지만 아직 도착하지 않았을 때) && 현재 도로가 cur보다 작거나 같다면
    살펴볼 대상이므로 check
4. 현재 도로가 cur보다 작거나 같지만 check가 안되있다면 해당 도로 stuck
5. 모든 도로가 교착 상태라면 break
6. check된 도로의 차량이 교차로 통과하는 시각 ans에 넣어주기
*/

#include <iostream>
#include <queue>
using namespace std;

int n, t, cur = 1e9, ans[200001];
char c;
queue<pair<int, int>> q[4];

bool qEmpty() {
    for (int i = 0; i < 4; i++)
        if (q[i].size()) return false;
    return true;
}

bool allStuck(bool* arr) {
    for (int i = 0; i < 4; i++)
        if (!arr[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    fill(ans, ans + n, -1);

    for (int i = 0; i < n; i++) {
        cin >> t >> c;
        q[c - 'A'].push({ t,i });
        cur = min(cur, t);
    }

    while (!qEmpty()) {
        // 도로의 front가 모두 cur 보다 시간이 크다면 cur를 그중 가장 작은 값으로 갱신
        int mint = 1e9;
        for (int i = 0; i < 4; i++)
            if (q[i].size()) mint = min(mint, q[i].front().first);
        cur = max(cur, mint);

        bool chk[4] = { 0 };
        bool isStuck[4] = { 0 };
      
        for (int i = 0; i < 4; i++)
            if (q[i].size()) {
                pair<int, int> now = q[i].front();

                if (q[(i + 3) % 4].empty() && now.first <= cur) // 오른쪽 도로에 더이상 차가 없는 경우
                    chk[i] = 1;

                if (!q[(i + 3) % 4].empty() &&
                    q[(i + 3) % 4].front().first > cur && now.first <= cur) // 오른쪽 도로에 차가 아직 안 온 경우
                    chk[i] = 1;

                if (!chk[i] && now.first <= cur)
                    isStuck[i] = 1;
            }

        if (allStuck(isStuck)) break;   // 모든 도로가 차있다면 break

        // check된 도로 대상으로 시간 갱신
        for (int i = 0; i < 4; i++)
            if (chk[i]) {
                ans[q[i].front().second] = cur;
                q[i].pop();
            }

        cur++;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}
