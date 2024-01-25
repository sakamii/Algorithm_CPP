#include <iostream>
#include <stack>
using namespace std;

int main() {
	string a;
	cin >> a;
	int answer = 0;
	stack<int>A; 
	//char로 넣으면 일의 자리수가 아닌 수를 다시 push 하게 될 때 문제가 됨
	//따라서 int로 설정(아스키코드로)
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ')') {
			int temp = 0;
			while (!A.empty()) {
				int top1 = A.top();
				A.pop();
				if (top1 > 1000) {
					temp += top1 - 1000;
					continue;
				}
				if (top1 == '(') break;
				else temp++;
			}
			if (A.empty()) continue;
			else {
				int top1 = (int)A.top()-'0';
				A.pop();
				if (top1 > 1000) {
					answer = temp * (top1 - 1000);
				}
				else if (top1 == '(') answer = temp;
				else answer = temp * top1;
			}
			if(answer!=0) A.push(answer+1000);
		}
		else A.push(a[i]);
	}
	int answer1 = 0;
	while (!A.empty()) {
		int top1 = A.top();
		A.pop();
		if (top1 > 1000) {
			answer1 += top1 - 1000;
			continue;
		}
		answer1++;
	}
	cout << answer1;
}
