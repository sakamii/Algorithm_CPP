
// https://www.acmicpc.net/problem/1662

/* 재귀 사용 */
#include <iostream>
using namespace std;

string  s;
bool vis[51];

int dfs(int idx) {
	int ret = 0;

	for (int i = idx; i < s.size(); i++)
		if (!vis[i]) {
			vis[i] = 1;
			if (s[i] == '(') ret += int(s[i - 1] - '0') * dfs(i + 1) - 1;
			else if (s[i] == ')') return ret;
			else ret++;
		}
	return ret;
}

int main() {
	cin >> s;
	cout << dfs(0);
}


/* 스택 사용 */
//#include <iostream>
//#include <stack>
//using namespace std;
//
//stack<int> st;
//string s;
//int ans, mul = 1;
//
//int main() {
//	cin >> s;
//	st.push(1);
//
//	for (int i = 0; i < s.size(); i++) {
//		ans += mul;
//
//		if (s[i] == '(') {
//			ans -= mul * 2;
//			mul *= (s[i - 1] - '0');
//			st.push(mul);
//		}
//
//		if (s[i] == ')') {
//			ans -= mul;
//			st.pop();
//			mul = st.top();
//		}
//	}
//	cout << ans;
//}
