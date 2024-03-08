#include<iostream>
using namespace std;

/*
	문제를 해석해 보았을 때 정답은 배열의 그룹의 수와 동일하다.
	그룹의 수를 count 할 때 배웠던 union find가 먼저 생각나서
	union find를 사용해서 문제 해결
*/

// cnt : filp 횟수
int N, M, cnt;
// union 배열
int map[1000002];
// 바이너리 길 상태 배열
int load[1000002];

void init() {
	for (int i = 1; i <= N; i++) {
		map[i] = i;
	}
}

int find(int tar) {
	if (tar == map[tar]) return tar;
	int ret = find(map[tar]);
	map[tar] = ret;

	return ret;
}

void uni(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	// 같은 그룹이 아닌 경우 union 하면서
	// 그룹수 -1;
	map[t2] = t1;
	cnt--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	init();

	cnt = 0;

	for (int i = 1; i <= N; i++) {
		cin >> load[i];
		// 처음 입력된 더러운칸 count
		if (load[i] == 1) cnt++;
		// 현재 칸이 더러우면 이전칸도 더러운지 확인하고
		// 더러우면 union
		if (load[i] != 0 && load[i - 1] == 1) uni(i, i - 1);
	}

	for (int i = 0; i < M; i++) {
		int state;
		cin >> state;

		if (state == 0) {
			cout << cnt << "\n";
		}
		else if (state == 1) {
			int idx;
			cin >> idx;

			// idx에 해당하느 길을 더럽혔으면
			// 우선 그룹의 수를 먼저 +1 해준다.
			// 만약 연결되는 길이라면 union 하는 과정에서 -1을 해주면 된다.
			if (load[idx] != 1) {
				cnt++;
				load[idx] = 1;
				// 왼쪽 오른쪽 각각 확인
				if (load[idx - 1] == 1) uni(idx, idx - 1);
				if (load[idx + 1] == 1) uni(idx, idx + 1);
			}
		}
	}

	int de = -1;

	return 0;
}
