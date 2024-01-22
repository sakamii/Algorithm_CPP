
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {

	// [ 1, 2, 3, 4, 5, 6, 7, 8, 9 (top)<-
	for (int i = 1; i < 10; i++)
		s.push(i);


	// 9 8 7 6 5 4 3 2 1
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
