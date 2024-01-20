
// https://www.acmicpc.net/problem/1168

#include <iostream>
using namespace std;

int n, k, x, tree[4000001];

int init(int node, int s, int e) {
	if (s == e) return tree[node] = 1;
	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

int query(int node, int s, int e, int idx) {
	tree[node]--;
	if (s == e) return s;
	int mid = (s + e) / 2;
    
	if (idx <= tree[node * 2]) return query(node * 2, s, mid, idx);
	else return query(node * 2 + 1, mid + 1, e, idx - tree[node * 2]);
}

int main() {
	cin >> n >> k;
	init(1, 1, n);
	cout << '<';
	x = k;
	for (int i = 0; i < n; i++) {
		cout << query(1, 1, n, x);
  if (tree[1]) cout << ", ";
  else break;
		x += k - 1;
		x = x % tree[1] ? x % tree[1] : tree[1];
	}
	cout << '>';
}
