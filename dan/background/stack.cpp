#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int>st; // 비어있는 int stack 선언
	stack<int>st2;

	// 스택에 쌓기
	st.push(1); // 1
	st.push(2); // 1 2
	st2.push(10); // 10
	st2.push(20); // 20

	// 두 스택의 내용물 스왑하기
	swap(st, st2);

	// 스택이 빌때까지 꺼내기
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}
