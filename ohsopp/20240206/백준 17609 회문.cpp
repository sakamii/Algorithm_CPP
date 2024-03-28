
// https://www.acmicpc.net/problem/17609

#include <iostream>
using namespace std;

int n;
string s;

int dfs(int l, int r, int c, bool flag) {
	if (l > r) return min(c, 2);	// c: 문자열에서 s[l]과 s[r]이 달랐던 횟수

	int ret = 2;
	if (s[l] == s[r]) // 양쪽 문자가 같으면 양쪽 한 글자씩 줄이면서 dfs 진행
		return dfs(l + 1, r - 1, c, flag);
	else {	// 양쪽 문자가 다를 때
		if (!flag) {	// 다른 적이 처음이라면
				ret = dfs(l + 1, r, c + 1, 1);	// 왼쪽 줄여서 진행한 것과
				ret = min(ret, dfs(l, r - 1, c + 1, 1)); // 오른쪽 줄여서 진행한 것중 작은 값으로
		}
		else ret = 2;	// 이미 전적이 있다? 바로 2 반환
		return ret;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << dfs(0, s.size() - 1, 0, 0) << endl;
	}
}
