#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;
	int answer = 0;
	stack<int>A; 
	//char로 넣으면 일의 자리수가 아닌 수를 다시 push 하게 될 때 문제가 됨
	//따라서 int로 설정(아스키코드로)
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ')') { //닫히는 괄호가 나오기 전까지 push. 그 전에 무조건 열리는 괄호 있음
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
			if (A.empty()) continue; //처음 부분이 ()...로 시작하는 경우
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
			//1000을 넘어가는 아스키코드는 없다고 판단,18번줄에서 구분하기 위해 1000을 더한다.
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
