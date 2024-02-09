#include <iostream>
#include <stack>
using namespace std;

int n, m, ans, arr[335][335];
char ch;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			arr[i][j] = ch == '0';
			if (arr[i][j]) arr[i][j] += arr[i - 1][j];
		}

	for (int i = 1; i <= n; i++) {
		stack<int> st;
		st.push(0);

		for (int j = 1; j <= m + 1; j++) {
			while (!st.empty() && arr[i][st.top()] > arr[i][j]) {
				int idx = st.top();
				st.pop();
				ans = max(ans, arr[i][idx] * (j - st.top() - 1));
			}
			st.push(j);
		}
	}
	cout << ans;
}
