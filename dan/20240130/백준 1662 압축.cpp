#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<int>st;
	string s;
	int tmp, mini, answer=0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.pop();
			st.push((int)(s[i - 1]-48));
			st.push(-1);
		}
		else if (s[i] == ')') {
			tmp = 0;
			while (st.top() != -1) {
				tmp += st.top();
				st.pop();
			}
			st.pop();
			mini = st.top() * tmp;
			st.pop();
			st.push(mini);
		}
		else {
			st.push(1);
		}
	}
	while (!st.empty()) {
		int i;
		i = st.top();
		answer += i;
		st.pop();
	}
	cout << answer;
}
