
#include <iostream>
#define ll long long
using namespace std;

int n, m, k;
ll a, b, c, arr[1000001];
ll tree[4000001];
int M = 1000000007;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = (init(node * 2, s, mid) * init(node * 2 + 1, mid + 1, e)) % M;
}

ll query(int node, int s, int e, int l, int r) {

	if (l <= s && r >= e) return tree[node];
	if (s > r || e < l) return 1;

	int mid = (s + e) / 2;
	return (query(node * 2, s, mid, l, r) * query(node * 2 + 1, mid + 1, e, l, r)) % M;
}

void update(int node, int s, int e, int idx, ll val) {
	if (idx < s || idx > e) return;

	if (s == e) {
		tree[node] = val;
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);

	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;

		if (a == 1)
			update(1, 1, n, b, c);
		else
			cout << query(1, 1, n, b, c) << '\n';
	}
}
