
#include <iostream>
#define NUM 10
using namespace std;

int arr[NUM] = { 3, 4, 1, 2, 5, 7, 3, 4, 9, 1 };

// 리프 노드 개수 곱하기 4만큼 할당
int tree[4 * NUM];

int init(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];

	int mid = (s + e) / 2;

	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

// 구간 최소값
int getMinQuery(int s, int e, int node, int l, int r) {

	if (l > e || r < s) return 1e9;

	if (s == e) return tree[node];

	int mid = (s + e) / 2;

	return min(getMinQuery(s, mid, node * 2, l, r), getMinQuery(mid + 1, e, node * 2 + 1, l, r));
}

int sum(int s, int e, int node, int l, int r) {
	// l, r이 합을 구해야하는 구간
	if (l > e || r < s) return 0;

	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

void update(int s, int e, int node, int idx, int diff) {
	if (idx < s || idx > e) return;

	tree[node] = tree[node] + diff;

	if (s != e) {
		int mid = (s + e) / 2;
		update(s, mid, node * 2, idx, diff);
		update(mid + 1, e, node * 2 + 1, idx, diff);
	}
}

int main() {

	// 세그먼트 트리 초기화
	init(0, NUM - 1, 1);
	
	// i번째 리프 노드 차례로 출력
	// 3 4 1 2 5 7 3 4 9 1
	for (int i = 0; i < NUM; i++)
		cout << sum(0, NUM - 1, 1, i, i) << " ";
	cout << endl;

	// 4~8번째 구간 최소값 : 3
	cout << getMinQuery(0, NUM - 1, 1, 4, 8) << endl;

	// 0~3번째 구간합 : 10
	cout << sum(0, NUM - 1, 1, 0, 3) << endl;

	// 0~9번째 구간합 : 39
	cout << sum(0, NUM - 1, 1, 0, NUM - 1) << endl;

}
