
// https://www.acmicpc.net/problem/1687

#include <iostream>
#include <stack>
using namespace std;

int n, m, ans, mat[335][335];
char ch;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			mat[i][j] = ch == '0';
			if (mat[i][j]) mat[i][j] += mat[i - 1][j];
		}

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
