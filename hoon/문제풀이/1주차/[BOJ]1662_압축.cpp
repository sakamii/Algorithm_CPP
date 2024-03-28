#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
int visited[50];
int func(int idx) {
	int cnt = 0;
	for (int i = idx; i < str.length(); i++) {
		char ch = str[i];
		if (ch == '('&& visited[i] == 0) {
			visited[i] = 1;
			cnt -= 1;
			cnt += (str[i-1]-'0') * func(i+1);
		}
		else if (ch == ')'&& visited[i] == 0) {
			visited[i] = 1;
			return cnt;
		}
		else if(visited[i] == 0) {
			visited[i] = 1;
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	cin >> str;
	cout << func(0);
	return 0;
}

/*
3년전에 틀렸던 문제

재귀로 구현
문자열의 길이를 계속 더하다가 
'('를 만나면 길이를 -1하고 이전 인덱스에 있던 숫자를 (다음에 나올 문자열에 곱해줌.
)는 문자열의 길이에 포함되지 않기 때문에 그대로 리턴.

괄호안에 아무것도 안들어오면 그 부분의 길이는 0


*/