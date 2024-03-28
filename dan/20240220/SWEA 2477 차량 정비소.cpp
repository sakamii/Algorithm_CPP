#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 시간에 따른 패턴이 보이지 않기 때문에 패턴을 찾지 않고 그냥 문제 그대로 구현
// 접수창구 대기열 rec_wait, 접수창구의 대기시간 배열 rect_t(n), 접수창구 배열 rec(n),
// 정비창구 대기열 fix_wait, 정비창구의 대기시간 배열 fix_t(m), 정비창구 배열 fix(m)
// 고객 도착시간 큐 k
// 지갑 두고 간 사람 접수창구 a, 정비창구 b
int t, n, m, k, a, b;
struct consumer {
	int id;
	int ar;
	int re;
	int fi;
};
queue<int>rec_wait, fix_wait; // consumer 인덱스가 하나씩 들어감 
int rec_t[10], fix_t[10];
int rec[10][2], fix[10][2];
 

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;
		vector<consumer>con;
		cin >> n >> m >> k >> a >> b;
		for (int i = 1; i <= n; i++) cin >> rec_t[i];
		for (int i = 1; i <= m; i++) cin >> fix_t[i];
		for (int i = 0; i < k; i++) {
			int a; cin >> a;
			con.push_back({ i, a, 0, 0 }); // 컨슈머 인덱스, 컨슈머 도착시간
		}
		// 이제 시간 1씩 더하면서 그냥 들어감
		// 모든 대기열이 빈 경우 = 즉, 그 사람이 언제 나갔는지 상관 없이 마지막 사람이 정비 창구에
		// 들어가기만 하면 어디 들어갔는지 알게 되니까 걍 break할거임
		int now_t = 0, con_cnt = 0; // now_t: 시간, con_cnt: 컨슈머 카운트 
		int de = -1;
		while (true) {
			if (con_cnt == k)break;
			// 정비 창구 시간 계산
			for (int i = 1; i <= m; i++) {
				if (fix[i][1] > 0) {
					fix[i][1]--;
					// 나갈 곳 없으니까 그냥 빼주기만 함
					if (fix[i][1] == 0) con_cnt++;
				}
				// 접수창구 대기열에 사람이 있고 접수창구가 비어있는 경우
				if (!fix_wait.empty() && fix[i][1] == 0) {
					fix[i][0] = fix_wait.front();
					fix[i][1] += fix_t[i];
					con[fix_wait.front()].fi = i;
					fix_wait.pop();
				}
			}

			// 접수 창구 시간 계산
			for (int i = 1; i <= n; i++) {
				if (rec[i][1] > 0) { // 사용하고 있는 사람이 있다는 뜻
					int de2 = -1;
					rec[i][1]--;
					// 시간 1이 지나니까 접수 창구 이용 시간이 딱 맞은 경우
					// 정비 창구로 이동해야함
					if (rec[i][1] == 0) {
						int flag = 0;
						for (int j = 1; j <= m; j++) { // 빈 자리 쫙 돌면서 있으면 들어감
							if (fix[j][1] == 0) {
								flag = 1;
								fix[j][0] = rec[i][0];
								fix[j][1] += fix_t[j];
								// 정비 창구 어디 갔는지 적기
								con[rec[i][0]].fi = j;
								break;
							}
						}
						// 빈 자리가 없는 경우 접수창구 대기열에 사람을 넣음
						if (flag == 0) fix_wait.push(rec[i][0]);
					}
				}
				// 접수창구 대기열에 사람이 있고 접수창구가 비어있는 경우
				if (!rec_wait.empty() && rec[i][1] == 0) {
					rec[i][0] = rec_wait.front();
					rec[i][1] += rec_t[i];
					con[rec_wait.front()].re = i;
					//cout << rec_wait.front() << ":" << i << endl;
					rec_wait.pop();
				}
			}

			// 센터에 사람이 옴
			for (int i = 0; i < con.size(); i++) {
				if (con[i].ar == now_t) { // 센터에 도착했다면
					int flag = 0;
					for (int j = 1; j <= n; j++) { // 빈 자리 쫙 돌면서 있으면 들어감
						if (rec[j][1] == 0) {
							flag = 1;
							rec[j][0] = con[i].id;
							rec[j][1] += rec_t[j];
							// 접수 창구 어디로 갔는지 적기
							con[i].re = j;
							//cout << i << ":" << j << endl;
							break;
						}
					}
					// 빈 자리가 없는 경우 접수창구 대기열에 사람을 넣음
					if (flag == 0) {
						rec_wait.push(con[i].id);
					}
				}
			}
			now_t++;
		}
		for (int i = 0; i < k; i++) {
			if (con[i].re == a && con[i].fi == b) {
				ans += i + 1;
			}
		}
		if (ans != 0)cout << "#" << tc << " " << ans << endl;
		else cout << "#" << tc << " " << -1 << endl;
	}
}
