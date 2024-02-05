
// https://www.acmicpc.net/problem/1687

#include <iostream>
#include <stack>
using namespace std;

int n, m, ans, tree[2000], mat[335][335];
char ch;

// segment-tree (메모리 초과)
/*
int init(int s, int e, int node, int row) {
	if (s == e) return tree[node] = s;		// 리프 노드값 설정

	int mid = (s + e) / 2;
	int left = init(s, mid, node * 2, row);
	int right = init(mid + 1, e, node * 2 + 1, row);

	return tree[node] = mat[row][left] < mat[row][right] ? left : right;
}

int query(int s, int e, int node, int l, int r, int row) {
	if (e < l || s > r) return -1;

	if (s >= l && e <= r) return tree[node];

	int mid = (s + e) / 2;
	int left = query(s, mid, node * 2, l, r, row);
	int right = query(mid + 1, e, node * 2 + 1, l, r, row);

	if (left < 0) return right;
	else if (right < 0) return left;
	else return mat[row][left] < mat[row][right] ? left : right;
}

void solve(int left, int right, int row) {
	if (left > right) return;

	int idx = query(0, n - 1, 1, left, right, row);
	ans = max(ans, mat[row][idx] * (right - left + 1));

	solve(left, idx - 1, row);
	solve(idx + 1, right, row);
}
*/

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			mat[i][j] = ch == '0';
			if (mat[i][j]) mat[i][j] += mat[i - 1][j];
		}

	/*for (int i = 1; i <= n; i++) {
		fill(tree, tree + 2000, 0);
		init(0, m - 1, 1, i);
		solve(0, m - 1, i);
	}*/

	for (int i = 1; i <= n; i++) {
		stack<int> st;
		st.push(0);
    
		for (int j = 1; j <= m + 1; j++) {
			while (!st.empty() && mat[i][st.top()] > mat[i][j]) {
				int idx = st.top();
				st.pop();
				ans = max(ans, mat[i][idx] * (j - st.top() - 1));
			}
			st.push(j);
		}
	}
	cout << ans;
}
