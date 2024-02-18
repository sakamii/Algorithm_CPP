#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n;
int sum1 = 0, sum2 = 0, ans = 999999999;
int vil[9][9] = { 0 };
int visited[9] = { 0 };
int people[9];
// 일단 마을을 나눌건데, 마을에 들어간 사람이 한 명이라도 있으면 돌아가는
// 마을을 나눠주는 dfs를 할거임 -> 1, 234 또는 23, 14 등등으로 나눠지겠지
// 마을이 나눠지면 그 안에서 bfs를 또 돌거임 이거는 그 뭐냐 1번 그룹이 이미 정해진 상태에서
// 나머지 애들이 연결되어있는지만 확인할 것. 연결되어있으면 얘네 유권자 수 비교하고 아니면 패스여

void dfs(int now) {
	if (now == n) return;
	if (now >= 1) {
		int check_idx1, check_idx2;
		int flag1 = 0, flag2 = 0;
		vector<int> visited1(9, 0);
		vector<int> visited2(9, 0);
		for (int i = 0; i < n; i++) {
			visited1[i] = visited[i]; // 1000
			visited2[i] = !visited[i];// 0111
			if (visited1[i] == 0) check_idx1 = i;
			if (visited2[i] == 0) check_idx2 = i;
		}
		queue<int>q;
		q.push(check_idx1);
		visited1[check_idx1] = 1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < n; i++) {
				int next = i;
				if (visited1[next] == 1)continue;
				if (vil[now][i] == 1) {
					q.push(next);
					visited1[next] = 1;
				}
			}
		}
		q.push(check_idx2);
		visited2[check_idx2] = 1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < n; i++) {
				int next = i;
				if (visited2[next] == 1)continue;
				if (vil[now][i] == 1) {
					q.push(next);
					visited2[next] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (visited1[i] != 1) {
				flag1 = 1;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (visited2[i] != 1) {
				flag2 = 1;
				break;
			}
		}
		if (flag1 == 0 && flag2 == 0) {
			sum1 = 0; sum2 = 0;
			for (int i = 0; i < n; i++) {
				if (visited[i] == 1) sum1 += people[i];
				else sum2 += people[i];
			}
			ans = min(ans, abs(sum1 - sum2));
		}
		else return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		dfs(now + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		ans = 99999999;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> vil[i][j];
			}
		}
		for (int i = 0; i < n; i++) cin >> people[i];
		for (int i = 0; i < n; i++) {
			visited[i] = 1;
			dfs(1);
			visited[i] = 0;
		}
		cout << "#" << tc+1 << " " << ans << endl;
	}
}
