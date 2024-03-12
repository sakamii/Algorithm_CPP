#include <iostream>

using namespace std;

/*
* 1차원 복도에서 연속된 더러운 구간을 알아야하므로
* 유니온 파인드를 쓰면 될거 같다고 생각함
* 민코딩에서 섬 개수나 바둑 문제를 경험하여서 그렇게 생각한듯
* 먼저 복도의 상태를 입력 받고 초기 상태에 연속된 더러운 구간을 구한다
* 계산은 DAT로 같은 부모를 가졌을 때 부모 배열을 카운팅한다 
* 이후 0일 때는 더러운 구간 갯수를 출력하고
* 1이면 양쪽을 확인하되 cnt를 이용해 union된 횟수를 센다
* union 횟수가 0이면 더러운 구간을 하나 증가시키고
* union 횟수가 1이면 원래 있던 구간에 union된 것이므로 그대로이며
* union 횟수가 2이면 원래 있던 두 구간이 하나로 union된 것이므로 더러운 구간을 하나 감소 시킨다
*/

int N, M;
int dirty;
int dx[] = { -1,1 };

bool aisle[1000000];
int parent[1000000];
int dirtyidx[1000000];


void init() {
	for (int i = 0; i < 1000000; i++) parent[i] = i;
}

int find(int tar) {
	if (tar == parent[tar]) return tar;
	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;
	parent[t2] = t1;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	cin >> N >> M;

	//복도 상태
	for (int i = 0; i < N; i++) {
		cin >> aisle[i];
	}

	//더러운 지역 연속구역 유니온
	for (int i = 0; i < N; i++) {
		if (aisle[i]) {
			for (int j = 0; j < 2; j++) {
				int nidx = i + dx[j];

				if (nidx < 0 || nidx >= N) continue;
				if (!aisle[nidx]) continue;
				if (find(i) == find(nidx)) continue;
				setUnion(i, nidx);
			}
		}
	}

	//더러운 지역 세기
	for (int i = 0; i < N; i++) {
		if (aisle[i]) {
			dirtyidx[find(i)]++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (dirtyidx[i] > 0) dirty++;
	}


	//시련시작
	for (int i = 0; i < M; i++) {
		bool test;
		cin >> test;
		if (!test) {
			cout << dirty << "\n";
		}
		else { //복도더러워짐
			int idx;
			cin >> idx;
			idx -= 1; //i번째가 1부터 시작이라 i-1로 해줘야한다
			if (!aisle[idx]) {
				aisle[idx] = !aisle[idx];
				int cnt = 0;
				for (int j = 0; j < 2; j++) {
					int nidx = idx + dx[j];

					if (nidx < 0 || nidx >= N) continue;
					if (!aisle[nidx]) continue;
					if (find(idx) == find(nidx)) continue;
					setUnion(idx, nidx);
					cnt++;
				}
				if (cnt == 0) dirty++;
				else if (cnt == 2) dirty--;
			}
		}
	}

	return 0;
}